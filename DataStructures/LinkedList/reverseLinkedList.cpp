#include <iostream>
#include <list>

using namespace std;

void printLL(list<int> &linkedList){
  for(auto it = linkedList.begin(); it!=linkedList.end(); it++) cout<<*it<<"\n";
}

void reverseList(list<int> &linkedList){
  auto it2 = linkedList.begin();
  for (auto it = linkedList.end(); it != linkedList.begin(); it++){
    int temp = *it;
    *it = *it2;
    *it = temp;
    it2++;
    if(it2 == it || it++ == it2) break;
  }
}

int main(){
  list<int> ll = {5,4,3,2,1};
  ll.reverse();
  printLL(ll);
//  reverseList(ll);
//  for(auto it = ll.begin(); it!=ll.end(); it++) cout<<*it<<"\n";
  return 1;
}
