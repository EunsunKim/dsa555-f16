#include <cstdlib>
#include <iostream>
#include <fstream>
#include "timer.h"

using namespace std;
void Merge(int arr[],int tmp[],int startA,int startB,int endB);

void MergeSort(int arr[],int tmp[],int start,int end){
  //if the array is more than one element big
  if(start<end){
    int mid=(start+end)/2;
    MergeSort(arr,tmp,start,mid);
    MergeSort(arr,tmp,mid+1,end);
    Merge(arr,tmp,start,mid+1,end);
  }
}
/*function merges the two halfs of a sorted array together.
  The arrays are defined from arr[startA]to arr[startB-1] and arr[startB]
to arr[endB]*/

void Merge(int arr[],int tmp[],int startA,int startB,int endB){
  int aptr=startA;
  int bptr=startB;
  int idx=startA;
  while(aptr < startB && bptr < endB+1){
    if(arr[aptr] < arr[bptr]){
       tmp[idx]=arr[aptr];
       idx++;
       aptr++;
    }
    else{
       tmp[idx++]=arr[bptr];
       bptr++;
    }
  }
  //merge function only does one of the two following loops
  while(aptr<startB){
    tmp[idx]=arr[aptr];
    idx++;
    aptr++;    
  }
  while(bptr < endB+1){
    tmp[idx++]=arr[bptr];
    bptr++;
  }

  //copy back into arr
  for(int i=startA;i<=endB;i++){
    arr[i]=tmp[i];
  }
}

/*this is the wrapper function that "main" uses.  The world see's this and
  use this. The actual work is done by the other MergeSort() function*/
void MergeSort(int arr[],int size){
  int* tmp=new int[size];
  MergeSort(arr,tmp,0,size-1);
  delete [] tmp;
}


int main(int argc, char* argv[]){
  int size=atoi(argv[1]);
  int *myarr=new int[size];
  Timer stopwatch;
  ofstream log("mergelog.txt");
  for(int i=0;i<size;i++){
    myarr[i]=rand();
//    myarr[i]=i+1;
  }
  stopwatch.start();
  MergeSort(myarr,size);
  stopwatch.stop();
  cout << stopwatch.currtime() << endl;
/*  for(int i=0;i<size;i++){
    log <<myarr[i]<< endl;
  }*/
  delete [] myarr;
  return 0;
}

