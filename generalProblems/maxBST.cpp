/**
  This program takes an array and 2 numbers contained in the array.  It 
  returns the largest number between those 2 numbers in the array
  @author Goodwin McDonald
  @date 3/7/2017
*/

#include <iostream>
#include <set>
#include <unordered_set>

/**
  Returns the largest number between two numbers in an array.  The function
  operates O(n) where n is the size of the array because it has to insert all
  elements in the array into a BST so that the array is automatically ordered
  without effecting the structure of the array that is passed.  
  @param *array A pointer to the array
  @param size Size of the array
  @param a The lower number in the array
  @param b The higher number in the array
  @ret max The highest number between a and b
*/
int findMaxBetween(int array[], int size, int a, int b){
  std::set<int> s;
  for(int i=0; i<size; i++) {						//insert all array elements into a BST.  This is
    if(a < array[i] < b) s.insert(array[i]);					//beneficial sense it orders the elements also
  }
  return *s.end();
}

int main(){
  int array[] = {30,8,20,5,6,10,31,72,67,56};
  int size = sizeof(array)/sizeof(array[0]);
  std::cout<<findMaxBetween(array, size, 20, 60)<<"\n";
  
  return 1;
}
