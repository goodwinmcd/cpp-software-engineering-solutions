/**
  This is an implementation of a Stack data structure using a singly linked list
*/

#include <iostream>


class Stack{
  private:
    struct Node{
      int data;
      Node* next;
    };
    Node head;
    int size;
  public:
    Stack();
    ~Stack();
    int getSize();
    void push(int val);
    int pop();
    void printStack();
};

/**
  Constructor that creates an empty stack
*/
Stack::Stack(){
  head.data = 0;
  head.next = NULL;
}

/**
  Deconstructor
*/
Stack::~Stack(){
}

/**
  Method to return size of the stack
*/
int Stack::getSize(){
  return size;
}

/**
  Method to push an object to the "top" of the stack
*/
void Stack::push(int val){
  Node* newNode = new Node;
  newNode->data = val;
  if(size == 0) newNode->next = NULL;
  else newNode->next = head.next;
  head.next = newNode;
  size++;
}

/**
  Method to remove last inserted object from the stack
  @ret returnVal The object that was "popped"
*/
int Stack::pop(){
  if(size == 0) std::cout<<"list is empty \n";
  else{
    int returnVal = head.next->data;
    head.next = head.next->next;
    size--;
    return returnVal;
  }
}

/**
  Method to print all objects contained in the stack
*/
void Stack::printStack(){
  if(size == 0) std::cout<<"List is empty \n";
  else{
    Node it = *head.next;
    while(it.next != NULL){
      std::cout<<it.data<<"\n";
      it = *it.next;
    }
    std::cout<<it.data<<"\n";
  }
}


int main(){
  Stack s;
  s.push(8);
  s.push(30);
  s.push(40);
  s.printStack();
  s.pop();
  s.pop();
  s.printStack();

  return 1;
}
