/**
  A program that splits a linked list in half
*/

#include <iostream>
#include <list>


int main(){
  std::list<int> list = {5, 9, 4, 3, 21};
  int size = list.size();
  int halfSize = size/2;
  std::cout<<"Size: "<<  size << "\nHalf: "<< halfSize<<"\n";
  for(auto it = list.begin(); it != list.end(); it++){
    std::cout<<*it<<"\n";
  }
  int count = 0;
  std::list<int> l1;
  std::list<int> l2;
  for(auto it = list.begin(); it != list.end(); it++){
    if(count < halfSize) l1.push_front(*it);
    else l2.push_front(*it);
    count++;
  }

  std::cout<<"List1: \n";
  for(auto it = l1.begin(); it != l1.end(); it++){
    std::cout<<*it<<"\n";
  }

  std::cout<<"List2: \n";
  for(auto it = l2.begin(); it != l2.end(); it++){
    std::cout<<*it<<"\n";
  }
  return 1;
}
