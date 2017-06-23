/**
  This is an implementation of a singly linked list
*/

#include <iostream>

template <class T>
class SinglyLinkedList{
  public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void addToFront(T d);
    void addToBack(T d);
    void reverse();
    T removeFromFront();
    T removeFromBack();
    int getSize();
    void printList();
  private:
    struct Node{
      T data;
      Node* next;
    };
    Node head;
    Node tail;
    int size;
    void reverseHelper(Node* p);
};

/**
  Constructor that creates an empty list with a head and a tail
*/
template <class T>
SinglyLinkedList<T>::SinglyLinkedList(){
  size = 0;
  head.next = &tail;
  tail.next = NULL;
}

/**
  Deconstructor
*/
template <class T>
SinglyLinkedList<T>::~SinglyLinkedList(){
  
}

/**
  Method to return size of an array
  @ret size Size of the array
*/
template <class T>
int SinglyLinkedList<T>::getSize(){
  return size;
}

/**
  A method to add an object to the front of an array
  @param d The object to be added to the list
*/
template <class T>
void SinglyLinkedList<T>::addToFront(T d){
  Node* newNode = new Node();
  newNode->data = d;
  newNode->next = head.next;
  head.next = newNode;
  size++;
}

/**
  A method to add an object to the end of the list
  @param d Object to be added to the list
*/
template <class T>
void SinglyLinkedList<T>::addToBack(T d){
  Node* it = &head;
  Node* newNode = new Node();
  newNode->data = d;
  while(it->next != &tail) it = it->next;
  it->next = newNode;
  newNode->next = &tail;
  size++;
}

/**
  Method to remove an object from the front of the list ("pop")
  @ret data The element that was removed
*/
template <class T>
T SinglyLinkedList<T>::removeFromFront(){
  if(size == 0) {
    std::cout<<"The list is empty \n";
    return -1;
  }
  else{
    T data = head.next->data;
    head.next = head.next->next;
    size--;
    return data;
  }
}

/**
  A method to remove an object from the back of a list
  @ret data The element that was removed
*/
template <class T>
T SinglyLinkedList<T>::removeFromBack(){
  T data;
  if(size == 0) {
    std::cout<<"The list is empty \n";
    return -1;
  }
  else{
    Node* it = &head;			
    Node* it2 = &head;
    it = it->next;			//Set the first iterator one element ahead of the second iterator
    while(it->next != &tail) {
      it = it->next;
      it2 = it2->next;
    }
    data = it->data;
    it2->next = &tail;			//redirector pointer to tail of the list 
    size--;
    return data;
  }
}

/**
  Recursive method to reverse contents of a linked list
*/ 
template <class T>
void SinglyLinkedList<T>::reverse(){
  Node* it = head.next;
  reverseHelper(it);
}

template <class T>
void SinglyLinkedList<T>::reverseHelper(Node* p){
  Node* addr = p;			//Note that local variable is necessary here so that the value does not change every call
  if(addr->next == &tail){
    head.next->next = &tail;
    head.next = addr;
  }
  else{
    Node* nodeAddr = addr;
    addr = addr->next;
    reverseHelper(addr);		//recursive call
    addr->next = nodeAddr;
    addr = addr->next;
  }
}

/**
  Method to print contents of the list
*/
template <class T>
void SinglyLinkedList<T>::printList(){
  Node* it2 = head.next;
  while(it2->next != NULL) {
    std::cout<<it2->data<<"\n";
    it2 = it2->next;
  }
}

int main(){
  SinglyLinkedList<int> l;
  l.addToFront(5);
  l.addToFront(10);
  l.addToFront(3);
  l.addToBack(80);
  l.addToBack(90);
  l.printList();
  std::cout<<"-------\n";
  l.reverse();
  l.printList();
  return 1;
}
