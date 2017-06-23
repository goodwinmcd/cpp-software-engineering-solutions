/**Solution to problem 1 at http://www.shiftedup.com/2015/05/07/five-programming-problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour.
*Problem statement: Write three functions that compute the sum of the numbers in a given list using a for-loop, a while-loop, and recursion.
*Author: Goodwin McDonald 
*/

#include <iostream>

/**
  This method uses a for loop to sum all numbers in an array together
  @param a[] The array to be summed
  @param size The size of the array
  @ret Return sum of all nums in the array
*/
int forLoop(int a[], int size){
  int sum = 0;
  for(int i=0; i<size; i++) sum += a[i];
  return sum;
}

/**
  This method uses a while loop to sum all nums in an array
  @param a[] The array to be summed
  @param size The size of the array
  @ret Return sum of all nums in the array
*/
int whileLoop(int a[], int size){
  int sum = 0;
  int count = 0;
  while(count < size){
    sum += a[count];
    count++;
  }
  return sum;
}

/**
  This method uses a recursive method to sum all nums in the array
  @param a[] The array to be summed
  @param size The size of the array
  @param count The count of recursive calls
  @param sum The current sum of the nums
  @ret Return sum of all nums in the array
*/
int recursive(int a[], int size, int count, int sum){
  if(count == size) return sum;
  else{
    sum += a[count];
    count++;
    recursive(a, size, count, sum);
  }
}


int main(){
  int array[] = {1, 5, 2, 3, 4, 5};
  int size = sizeof(array)/sizeof(array[0]);
  int sum = forLoop(array, size);
  std::cout<<"The sum is "<<sum<<"\n";
  
  sum = whileLoop(array, size);
  std::cout<<"The sum is "<<sum<<"\n";

  sum = recursive(array, size, 0, 0);
  std::cout<<"The sum is "<<sum<<"\n";
  return 1;
}
