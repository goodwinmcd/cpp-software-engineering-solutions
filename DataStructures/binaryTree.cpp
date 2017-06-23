#include <iostream>

class binaryTree{
  public:
    binaryTree();
    ~binaryTree();
    void insert(int num);
    void remove(int num);
    void print();
  private:
    struct Node{
      int data;
      Node* left;
      Node* right;
    };
    Node head;
    int size;
    void insertR(int num, Node node);
};

binaryTree::binaryTree(){
  head.data = 0;
  head.left = NULL;
  head.right = NULL;
  size = 0;
}

void binaryTree::insert(int num){
  if(size = 0){
    head.data = num;
    size++;
  }
  else{
    insertR(num, head);
  }
}

void binaryTree::insertR(int num, Node node){
  if(num > node.data){
    if(node.left == NULL){
      Node* newNode = new Node();
      node.left = newNode;
      newNode->data = num;
      newNode->left = NULL;
      newNode->right = NULL;
      size++;
    }
    else insertR(num, *node.left);
  }
  else{
    if(node.right == NULL){
      Node* newNode = new Node();
      node.right = newNode;
      newNode->data = num;
      newNode->left = NULL;
      newNode->right = NULL;
      size++;
    }
    else insertR(num, *node.right);
  }
}


int main(){
  
  return 1;
}
