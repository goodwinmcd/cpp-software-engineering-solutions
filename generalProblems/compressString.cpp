/**
  This program compresses a string so that all repeated letters are 
  removed and replaced with how many times the letter is repeated. 
  i.e.- "thisss iis reppplacced" with "this3 i2s rep3lac3ed"
  @author Goodwin McDonald
  @date 3/7/2017
*/

#include <iostream>
#include <string>

/**
  Function iterates through string once and works in a O(n) 
  where n is the length of the string
  @ret newString The new compressed string
*/
std::string compress(std::string string){
  int count = 1;
  std::string newString;
  
  for(int i=0; i < string.length(); i++){
    while(string[i] == string[i+1]){				//if the current letter matches the next letter
      count++;							//then increment until not true
      i++;
    }
    if(count > 1){						//append number to string and reset count
      newString += string[i] + std::to_string(count);
      count = 1;
    }
    else {
      newString += string[i]; 
    }
  }
  return newString;
  }

int main(){
  std::string myString = "deerrp daaaaaaa derrrrrrrrrrrrrrrrrrp";
  std::string newString = compress(myString);
  std::cout<<newString<<"\n";
  return 1;
}
