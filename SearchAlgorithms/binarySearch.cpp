#include <iostream>

int binarySearch(int array[],int l, int r, int num){
  if(r >= l){
    int mid = l + (r-l)/2;
    if(array[mid] == num) return array[mid];
    if(array[mid] > num) return binarySearch(array, l, mid, num);
    if(array[mid] < num) return binarySearch(array, mid, r, num);
  }
  return -1;
}

int main(){
  int array[] = {1, 5, 6, 13, 33, 88, 122, 125, 133, 234, 533};
  int length = sizeof(array)/sizeof(array[0]);
  int found = binarySearch(array, 0, length-1, 51);
  if(found == -1) std::cout<< "Element not found \n";
  else std::cout<< "element found \n";
  return 1;
}
