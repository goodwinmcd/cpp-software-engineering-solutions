/**
  This program determines whether a string entered by the user contains a
  palindrone. 
  @author Goodwin McDonald
  @date 3/23/2017
*/

#include <iostream>
#include <string>
#include <unordered_set>

int main(){
  std::string myString;
  std::cout<<"Please enter a string: ";					//receive user input
  getline(std::cin, myString);

  std::unordered_set<int> us;	
  for(int i = 0; i < myString.length(); i++){				//each letter in the string is tested to see if it already exist in an
    auto found = us.find(myString[i]);					//unordered set.  If the letter is in the set it is removed.  If not it is
    if(found != us.end()) us.erase(myString[i]);			//inserted.  This means that for any palindrone the size of the set will be
    else us.insert(myString[i]);					//0 or 1.  The algorithm operates under O(n)
  }
  if(us.size() > 1) std::cout<<"This is not a palindrome \n";
  else std::cout<<"This is a palindrome \n";

  return 1;
}
