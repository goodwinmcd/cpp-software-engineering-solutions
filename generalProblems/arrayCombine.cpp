/*Solution to problem 2 at http://www.shiftedup.com/2015/05/07/five-programming-problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour
*Problem statement: Write a function that combines two lists by alternatingly taking elements. For example: given the two lists [a, b, c] and [1, 2, 3], the function should return [a, 1, b, 2, c, 3].
*/
#include <iostream>

/**
  Function that combines 2 arrays into 1
  @param a1 Array 1
  @param a2 Array 2
  @param a3 Array that is a combination of a1 and a2
  @param size Size of a1 and a2
*/
void combine(int a1[], int a2[], int a3[], int size){
	int counter=0;
	for(int i=0; i<size; i++){
	  std::cout<<"a1: " << a1[i] <<"\n";
	  std::cout<<"a2: " << a2[i] <<"\n";
	  a3[counter++] = a1[i];
	  a3[counter++] = a2[i];
	}
}

int main(){
	int array1[] = {1,3,5,7};
	int array2[] = {2,4,6,8};
	int array3[8];
	int size= sizeof(array1)/sizeof(array1[0]);
	combine(array1, array2, array3, size);
	for(int i=0; i<size*2; i++){
          std::cout<<array3[i]<<"\n";
	}
	return 1;
}
