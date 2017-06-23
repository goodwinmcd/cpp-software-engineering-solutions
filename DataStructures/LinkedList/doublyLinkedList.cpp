#include <iostream>
#include <string>

template <class T>
class DoublyLinkedList{
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void addToFront(T d);
    void addToBack(T d);
    void reverse();
    T removeFromFront();
    T removeFromBack();
    T findObj(T obj);
    int getSize();
    void printList();
  private:
    struct Node{
      T data;
      Node* next;
      Node* prev;
    };
    Node head;
    Node tail;
    int size;
    void switchN(Node* n1, Node* n2);
};

/**
*Constructor for our linked list
*/
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  head.next = &tail;
  tail.prev = &head;
}

/**
*Deconstructor
*/
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
}

/**
  Method to add a node to the front of the list
  
  @param d Object to add to the list
*/
template <class T>
void DoublyLinkedList<T>::addToFront(T d){
  Node* newNode = new Node();			//initialize new node data
  newNode->data = d;
  newNode->next = head.next;
  newNode->prev = &head;
  head.next->prev = newNode;			//have previous node in front point to
  head.next = newNode;				//new node and have head now point to 
  size++;					//new node
}

/**
  Method to add a new node to the end of the list

  @param d Object that the new node will contain
*/
template <class T>
void DoublyLinkedList<T>::addToBack(T d){
  Node* newNode = new Node();			//initialize all the new node values
  newNode->data = d;
  newNode->next = &tail;
  newNode->prev = tail.prev;
  tail.prev->next = newNode;			//Set the previous last element to point
  tail.prev = newNode;				//to new node and have tail point to new node
  size++;
}

/**
  A method to remove whatever is at the front of the
  list and return it to user.

  @return returnData The object that was removed and returned
  to user
*/
template <class T>
T DoublyLinkedList<T>::removeFromFront(){	
  T returnData = head.next->data;
  head.next = head.next->next;			//Make sure that no nodes point to node that
  head.next->prev = &head;			//is to be removed
  size--;
  return returnData;
}

/**
  Method to remove node from the end of the list
  and return what ever data it contained

  @return returnData The data that was contained in the node that
  was removed
*/
template <class T>
T DoublyLinkedList<T>::removeFromBack(){
  T returnData = tail.prev->data;
  tail.prev = tail.prev->prev;
  tail.prev->next = &tail;
  size--;
  return returnData;
}

/**
  Method to check if the list contains a specific object

  @param obj The object to look for in the list
*/
template <class T>
T DoublyLinkedList<T>::findObj(T obj){
  Node* it = &head;
  while(it->next != NULL){
    if(it->data == obj) break;
    it = it->next;
  }
  return it->data;
}

/**
  Method to reverse the linked list
*/
template <class T>
void DoublyLinkedList<T>::reverse(){
  Node* it1 = tail.prev;			//Set pointers to front and end of list
  Node* it2 = &head;
  while(it1 != &head){				//The algorithm sets the front pointers node
    Node* temp = it1->prev;			//to point to the back pointers node.  Now the
    it2->next = it1;				//front pointer points to the node that was just 
    it1->prev = it2;				//moved to the front and the back pointer points
    it2 = it1;					//to the node that is now last in the list
    it1 = temp;
  }
  it2->next = &tail;				//update pointer to tail
  tail.prev = it2;
}

/**
  Method to print the list
*/
template <class T>
void DoublyLinkedList<T>::printList(){
  Node* it = head.next;
  while(it->next != &tail) {
    std::cout<<it->data<<" <- -> ";
    it = it->next;
  }
  std::cout<<it->data;
  std::cout<<"\n";
}

int main(){
  DoublyLinkedList<int> dl;
  dl.addToFront(1);
  dl.addToFront(5);
  dl.addToFront(19);
  dl.addToBack(30);
  int obj = dl.findObj(5);
  std::cout<<obj<<"\n";
  dl.printList();
  dl.reverse();
  dl.printList();
  DoublyLinkedList<std::string> dl2;
  dl2.addToFront("derp");
  dl2.addToFront("hello");
  dl2.addToFront("world");
  dl2.printList();
  dl2.reverse();
  dl2.printList();
  return 1;
}
