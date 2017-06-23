/**
This is an implementation of a coding problem found at this site: http://www.byte-by-byte.com/consecutivearray/.
Problem statement: given an unsorted arbitrary array find the max sequence of
consecutive numbers. 
*/

#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

int returnSeq(int* array){
  unordered_set<int> hs;				//put the array in a
  for(int i=0; i<10; i++){				//hashset
    hs.insert(array[i]);
  }

  int maxSeq = 0;					//declare out ret value

  for(auto it=hs.begin(); it!=hs.end(); ++it){
    if(hs.count(*it-1) > 0) continue;			//ignore values that 
    							//are not start of a 
							//sequence

    int currentRun = 1;					//count the first num
    int currentNum = *it;
    while(hs.count(currentNum+1) > 0) {			//keep incrementing
      currentNum++;					//our run counter 
      currentRun++;					//until there is not
    }							//another sequential
    							//num

    if(currentRun > maxSeq) maxSeq = currentRun;	//update our max run
  }

  return maxSeq;
}

int main(){
  int a[10];
  for(int i=0; i<10; i++){
    a[i] = rand() % 10;
  }
  sort(a, a+10);
  for(int i=0; i<10; i++){
    cout<<a[i]<<"\n";
  }
  cout<<"----------------\n";
  int* p = a;
  int answer = returnSeq(p);

  cout<<answer<<"\n";

  return 1;
}

