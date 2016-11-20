/****************************************/
/*                                      */
/*   This is the official tester for    */
/*   assignment 3                       */
/*   DSA555 - Fall 2016                 */
/*                                      */
/*                                      */
/*   Your code must pass all tests      */
/*   on matrix                          */
/*                                      */
/*   To compile on matrix:              */
/*   g++ a3main.cpp -std=c++0x          */
/*                                      */
/****************************************/
#include "threadedtree.h"
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
//The next line allows extra output
//when things go wrong
//change it to 1 to show a the list content (and what it should be)
//or a number more than 1 for a lot of output (not recommended... too much)
#define VERBOSE 0


struct Record{
	char word_[30];
	int count_;

};
ostream& operator<<(ostream& os, const Record rec){
	os << rec.word_;
	return os;
}
bool operator<(const Record& lhs, const Record& rhs){
	bool rc=false;
	if(strcmp(lhs.word_,rhs.word_) < 0){
		rc=true;
	}
	return rc;
}
bool operator>(const Record& lhs, const Record& rhs){
	bool rc=false;
	if(strcmp(lhs.word_,rhs.word_) > 0){
		rc=true;
	}
	return rc;
}
bool operator==(const Record& lhs, const Record& rhs){
	bool rc=false;
	if(strcmp(lhs.word_,rhs.word_)==0){
		rc=true;
	}
	return rc;
}
bool operator!=(const Record& lhs, const Record& rhs){
	bool rc=false;
	if(strcmp(lhs.word_,rhs.word_)!=0){
		rc=true;
	}
	return rc;
}
template <class T>
void mergeArray(T arr[],T tmp[],int startA,int startB,int endB);
template <class T>
void mergeSort(T arr[],T tmp[],int start,int end);
template <class T>
void mergeSort(T arr[],int size);
int search(int key,int arr[],int size);
int main(void){
	bool passtest=true;
	int numPassed=0;
	int cap = 20000;


	Record data[20]={
		{"the",1},
		{"quick",2},
		{"brown ",3},
		{"fox",4},
		{"jumped",5},
		{"over",6},
		{"lazy",7},
		{"dog",8},
		{"Calvin",9},
		{"and",10},
		{"Hobbes",11},
		{"night",12},
		{"watch",13},
		{"captain",14},
		{"carrot",15},
		{"lilac",16},
		{"lavender",17},
		{"lily",18},
		{"coffee",19},
		{"tea",20}
	};

	//this array will mirror what happens to LL
	Record mirror[20];

	int intData[cap];
	int intMirror[cap];
	int recCap=20;
	ThreadedTree<Record>::const_iterator recIt;
	ThreadedTree<Record>::const_iterator recOld;
	ThreadedTree<int>::const_iterator intIt;
	ThreadedTree<int>::const_iterator intOld;
	for(int i=0;i<recCap;i++){
		mirror[i]=data[i];
	}
	mergeSort(mirror,recCap);

	for(int i=0;i<cap;i++){
		int randomNumber= rand();
		while(search(randomNumber,intData,i+1)!=-1){
			randomNumber=rand();
		}
		intMirror[i]=intData[i]=randomNumber;
	}
	mergeSort(intMirror,cap);

	/* Test constructors*/
	cout << "Test 1: create list empty list" << endl;
	ThreadedTree<Record> recTree;
	ThreadedTree<int> intTree;
	if((recTree.begin() != recTree.end()) || 
		(intTree.begin() != intTree.end())){
		cout << "Error 1: check your constructor, begin() and end() functions" << endl;
		passtest=false;
	}
	if(passtest){
		numPassed++;
		cout << "Test 2: put data into trees, check using iterator (++)  " << endl;
		for(int i=0;i<recCap;i++){
			recTree.insert(data[i]);
		}
		for(int i=0;i<cap;i++){
			intTree.insert(intData[i]);
		}
		recIt=recTree.begin();
		intIt=intTree.begin();
		bool isGood=true;
		for(int i=0;isGood && i<recCap-1;i++,recIt++){
			if(*recIt != mirror[i]){
				isGood=false;
			}
		}
		bool isGood2=true;
		for(int i=0;isGood2 && i<cap-1;i++, intIt++){
			if(*intIt != intMirror[i]){
				isGood2=false;
			}
		}
		if(!isGood2 || !isGood){
			passtest=false;
			cout << "Your tree is not as it should be or " << endl;
			cout << "iterator is not going through it correctly"  << endl;
#if VERBOSE >= 1
			auto it=recTree.begin();
			cout << "The following is a listing of your tree vs correct" << endl;
			cout << "your tree  --->   correct value"  << endl;
			for(int i=0;i<recCap-1;i++,*it++){
				cout << *it << " ---> " << mirror[i] << endl;
			}
#endif
#if VERBOSE > 1
			auto it2=intTree.begin();
			cout << "The following is a listing of your int tree vs correct" << endl;
			cout << "your tree  --->   correct value"  << endl;
			for(int i=0;i<cap-1;i++,*it2++){
				cout << *it2 << " ---> " << intMirror[i] << endl;
			}
#endif
		}
	}
	if(passtest){
		numPassed++;
		cout << "Test 3: Test the find() function" << endl;
		bool isGood=true;
		for(int i=0;isGood && i<recCap;i++){
			auto tmp = recTree.find(mirror[i]);
			if(*tmp != mirror[i]){
				isGood=false;
			}
		}
		bool isGood2=true;
		for(int i=0;isGood && i<recCap;i++){
			auto tmp = intTree.find(intMirror[i]);
			if(*tmp != intMirror[i]){
				isGood2=false;
			}
		}
	}

	if(passtest){
		numPassed++;
		cout << "Test 4: check operator ++"<< endl;
		recIt=recTree.begin();
		bool isGood=true;
		for(int i=0;isGood && i<recCap;i++){
			recOld=recIt++;
			if(*recOld != mirror[i]){
				isGood=false;
			}
		}
		intIt=intTree.begin();
		bool isGood2=true;
		for(int i=0;isGood2 && i<cap;i++){
			intOld=intIt++;
			if(*intOld != intMirror[i]){
				isGood2=false;
			}
		}
		if(!isGood || !isGood2 || 
			intIt != intTree.end() ||
			 recIt != recTree.end()){
			cout << "bug in operator ++, check its return value" << endl;
			passtest=false;
		}
	}
	if(passtest){
		numPassed++;
		cout << "Test 5: check operator -- "<< endl;
		recIt--;
		if(recIt==recOld){
			cout << "good job, looks like you got can go backwards from end()" << endl;
		}
		recIt=recOld;
		bool isGood=true;
		for(int i=recCap-1;isGood && i>=0;i--){
			recOld=recIt--;
			if(*recOld != mirror[i]){
				isGood=false;
			}
		}
		intIt=intOld;
		bool isGood2=true;
		for(int i=cap-1;isGood2 && i>=0;i--){
			intOld=intIt--;
			if(*intOld != intMirror[i]){
				isGood2=false;
			}
		}
		if(!isGood || !isGood2 || 
			intOld != intTree.begin() ||
			 recOld != recTree.begin()){
			cout << "bug in operator --, check its return value" << endl;
			passtest=false;
		}
	}
	if(passtest){
		numPassed++;
	}
 	if(numPassed == 5){
	 	cout << "Testing for Assignment 3 completed successfully" << endl;
	}
	else{
		cout << numPassed << " / 5 tests passed.  Looks like you still" << endl;
		cout << "have some work to do" << endl;
	}
	return 0;
}




template <class T>
void mergeSort(T arr[],T tmp[],int start,int end){
  //if the array is more than one element big
	if(start<end){
		int mid=(start+end)/2;
		mergeSort(arr,tmp,start,mid);
		mergeSort(arr,tmp,mid+1,end);
		mergeArray(arr,tmp,start,mid+1,end);
	}
}
/*function merges the two halfs of a sorted array together.
  The arrays are defined from arr[startA]to arr[startB-1] and arr[startB]
to arr[endB]*/

template <class T>
void mergeArray(T arr[],T tmp[],int startA,int startB,int endB){
	int aptr=startA;
	int bptr=startB;
	int idx=startA;
	while(aptr < startB && bptr < endB+1){
		if(arr[aptr] < arr[bptr]){
			tmp[idx++]=arr[aptr];
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
template <class T>
void mergeSort(T arr[],int size){
	T* tmp=new T[size];
	mergeSort(arr,tmp,0,size-1);
	delete [] tmp;
}

int search(int key,int arr[],int size){
	int rc=-1;
	for(int i=0;rc==-1 && i<size;i++){
		if(key==arr[i]){
			rc=i;
		}
	}
	return rc;
}


