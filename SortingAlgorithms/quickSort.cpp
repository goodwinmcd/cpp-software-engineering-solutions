#include <iostream>

int partition(int array[], int low, int high){
  int p = array[high];
  int j = low -1;
  int temp;
  for(int i = low; i < high; i++){
    if(array[i] < array[p]){
      j++;
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  j++;
  temp = array[j];
  array[j] = array[high];
  array[high] = temp;
  return j;
}

void quickSort(int array[], int low, int high){
  if(low < high){
    int pi = partition(array, low, high);
    quickSort(array, low, pi-1);
    quickSort(array, pi+1, high);
  }

}


int main(){
  int array[] = {30, 50, 20, 80, 90, 100, 70, 22, 33};
  int size = sizeof(array)/sizeof(array[0]);
  quickSort(array, 0, size);
  for(int i=0; i<size-1; i++) std::cout<<array[i]<<"\n";
}
