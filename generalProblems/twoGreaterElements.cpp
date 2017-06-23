/**
*This program will take an array and find every element
*that has at least two greater elements and print them
*/

#include <iostream>

/**
*This method has O(n^2)
*/
void findGreater(int array[], int size){
  for(int i=0; i<size; i++){
    int count = 0;
    for(int j=0; j<size; j++){
      if(array[j] > array[i]) count++;
      if(count == 2) {
	std::cout<<array[i]<<"\n";
	break;
      }
    }
  } 
}

/**
*This method will sort array first and print 
*every element exept the last two.  Assuming we
*sort in O(n*logn) then our algorithm will not 
*take any more time than that
*/
void sortFirst(int array[], int size){
  
}

int main(){
  int array[] = {5, 9, 2, 3, 34, 10, 100, 45, 22};
  int length = sizeof(array)/sizeof(array[1]);
  findGreater(array, length);
  return 1;
} 
