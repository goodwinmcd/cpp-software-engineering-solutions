/**
  This program determines if a linked list is a palindrone or now.  
  @author Goodwin Mcdonald
  @date 3/23/2017
*/

#include <iostream>
#include <list>

using namespace std;


int main(){
  list<int> linkedList = {5, 4, 3, 4, 5};
  list<int>::iterator i = linkedList.begin();
  list<int>::iterator j = linkedList.end();
  while(i != j){					//Create iterators at front and back of linked list.  If at any point the 
    if(*i != *j) cout<<"not a palindrone \n";		//iterators are not pointing to the equivalent elements then the list is not
  }							//a palindrone
  
  cout<< *i << " " << *j << "\n";

  return 1;
}
