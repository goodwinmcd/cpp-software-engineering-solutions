/**This program implements and test a Q data structure using a
*doubly linked list
*@author Goodwin McDonald
*/

#include <iostream>

template <class T> 
class Que{
  public:
    Que();
    ~Que();
    void push(T data);
    T pop();
    void printList();
    int getSize();
  private:
    struct Node{
      T data;
      Node* next;
      Node* previous;
    };
    Node head;
    Node tail;
    int size;
};

/**
*Constructor
*/
template <class T>
Que<T>::Que(){
  size = 0;
  head.previous = NULL;
  head.next = &tail;
  tail.previous = &head;
  tail.next = NULL;
}

template <class T>
Que<T>::~Que(){
}

/**
*Insert new object to front of list
*/
template <class T>
void Que<T>::push(T data){
  Node* newNode = new Node();			
  newNode->data = data;					
  newNode->next = head.next;				
  newNode->previous = &head;
  head.next->previous = newNode;			//what head.next was previously pointing to its new value 
  							//is now the address of the newNode
  head.next = newNode;					//head.next now pointing to address of newNode
  size++;
}

/*
*Return last item in list and remove it from Que
*/
template <class T>
T Que<T>::pop(){
  if(size == 0){ 
    std::cout<<"The list is empty \n";
    return -1;
  }
  else{
    T returnItem = tail.previous->data;
    tail.previous = tail.previous->previous;
    tail.previous->next = &tail;
    size--;
    return returnItem;
  }
}

/**
*Print Que
*/
template <class T>
void Que<T>::printList(){
  Node* it = head.next;
  while (it->next != NULL){
    std::cout<< it->data<<"\n";
    it = it->next;
  }
}

/**
*Return size of Que
*/
template <class T>
int Que<T>::getSize(){
  return size; 
}

int main(){
  Que<int> Q;
  int length = Q.getSize();
  std::cout<<"Size is: "<< length<< "\n";
  Q.push(8);
  Q.push(30);
  Q.push(40);
  Q.push(80);
  Q.printList();
  return 1;
}
