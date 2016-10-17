/*********************************************************************/
/*                                                                   */
/* Tester for DSA555 assignment 1, question 1                    	 */
/* Version 1.0                                                       */
/* To compile:                                                       */
/*                                                                   */
/*      g++ a1q1main.cpp -std=c++0x                                  */
/*                                                                   */
/*********************************************************************/

#include "a1q1.h"
#include <cstring>
#include <iostream>
using namespace std;
//change the #define VERBOSE to 1 for a bit more error information
#define VERBOSE 0

struct Record{
	char word_[30];
	int count_;
};
ostream& operator<<(ostream& os, const Record rec){
	os << rec.word_;
	return os;
}
bool operator==(const Record& a,const Record& b){
	bool rc=false;
	if(strcmp(a.word_,b.word_)==0 && a.count_==b.count_){
		rc=true;
	}
	return rc;
}
bool operator!=(const Record& a,const Record& b){
	return !(a==b);
}

template <typename T>
void adjust(int idx,T arr[]);
template <typename T>
void removeItem(T arr[],int idx,int sz);
template <typename T>
bool checkList(const RecentList<T>& list,const T arr2[],int sz);
template <typename T>
void duplicateArray(T dest[], const T src[],int sz);
template <typename T>
void printLists(const RecentList<T>& list,const T array[],int sz);

template<typename T>
typename RecentList<T>::iterator setIterator(RecentList<T>& list, int idx);

int main(void){
	const int cap=10000;
	const int numSearches=200;
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
	int intData[cap];

	//these array will mirror what happens to LL
	Record mirror[20];
	int intMirror[cap];



	RecentList<Record> recList;
	RecentList<int> intList;

	bool passtest=true;
	int numPassed=0;



	/* Test constructors, begin and end functions*/
	cout << "test 1: create list empty list, check begin() and end()" << endl;
	if((recList.begin() != recList.end()) || 
		(intList.begin() != intList.end())){
		cout << "error 1: check your constructor, begin() and end() functions" << endl;
		passtest=false;
	}
	else{
		numPassed++;
	}
	for(int i=0;i<20;i++){
		recList.insert(data[19-i]);
		mirror[i]=data[i];
	}
	for(int i=0;i<cap;i++){
		intList.insert(i);
		intData[cap-1-i]=i;
		intMirror[cap-1-i]=i;
	}
	cout << "test 2: create list, insert some records." << endl;
	if(!checkList(recList,mirror,20)){
		passtest=false;
		cout << "Error 2a: Bug in either constructor, insert() or iterator (operator++(int) or operator*)"<< endl;
	}
	if(!checkList(intList,intMirror,cap)){
		passtest=false;
		cout << "Error 2b: Bug in either constructor, insert() or iterator (operator++(int) or operator*)"<< endl;
	}
	if(passtest){
		numPassed++;
		cout << "test 3: check iterator ++ and -- operators"  << endl;
		auto it=recList.begin();
		for(int i=0;i<19 && passtest;i++){
			if(data[i] != *(it++)){
				passtest=false;
				cout << "Error 3a: postfix ++ operator is not returning iterator to correct node" << endl;
			}
		}
		for(int i=19;i>0 && passtest;i--){
			if(data[i] != *(it--)){
				passtest=false;
				cout << "Error 3b: postfix -- operator is not returning iterator to correct node" << endl;
			}
		}
		for(int i=0;i<19 && passtest;i++){
			if(*(++it) != data[i+1]){
				passtest=false;
				cout << "Error 3c: prefix ++ operator is not returning iterator to correct node" << endl;
			}
		}
		for(int i=19;i>0 && passtest;i--){
			if(*(--it) != data[i-1]){
				passtest=false;
				cout << "Error 3d: prefix -- operator is not returning iterator to correct node" << endl;
			}
		}
	}


	RecentList<Record> recCopy=recList;
	RecentList<int> intCopy=intList;
	if(passtest){
		numPassed++;
		cout << "test 4: create a duplicate of the lists with copy constructor, ensure they match" << endl;
		if(!checkList(recList,mirror,20)){
			passtest=false;
			cout << "Error 4a: Bug in copy constructor"  << endl;  		
		}
		if(!checkList(intList,intMirror,cap)){
			passtest=false;
			cout << "Error 4b: Bug in copy constructor" << endl;
		}
	}
	if(passtest){
		numPassed++;
		cout << "test 5: perform some searches, ensure adjustment is handled" << endl;
		for(int i=0;i<numSearches && passtest;i++){
			int pick=rand()%20;
			auto it = recList.search(mirror[pick]);
			if(it != recList.end() && *it == mirror[pick]){
				adjust(pick,mirror);
				if(!checkList(recList,mirror,20)){
					passtest=false;
					cout << "Error 5a: Bug in search." << endl;
					#if VERBOSE >=1
					cout << "searching for " << mirror[0] << endl;
					printLists(recList,mirror,20);
					#endif
				}

			}
			else{
				passtest=false;
				cout << "Error 5b: Bug in search, iterator returned does not point at correct node" << endl;
			}
		}
		for(int i=0;i<numSearches&& passtest;i++){
			int pick=rand()%cap;
			auto it = intList.search(intMirror[pick]);
			if(it != intList.end() && *it == intMirror[pick]){
				adjust(pick,intMirror);
				if(!checkList(intList,intMirror,cap)){
					passtest=false;
					cout << "Error 5c: Bug in search."<< endl;
				}
			}
			else{
				passtest=false;
				cout << "Error 5d: Bug in search, iterator returned does not point at correct node" << endl;
			}
		}
	}
	if(passtest){
		numPassed++;
		cout << "test 6: ensure that copied list were not altered (proper deep copy was made) " << endl;
		if(!checkList(recCopy,data,20)){
			passtest=false;
			cout << "Error 6a: Bug in copy constructor, deep copy not made?"  << endl;
			#if VERBOSE >= 1
			printLists(recCopy,data,20);
			#endif
		}
		if(!checkList(intCopy,intData,cap)){
			passtest=false;
			cout << "Error 6b: Bug in copy constructor, deep copy not made?" << endl;
			#if VERBOSE >= 2
			printLists(intCopy,intData,cap);
			#endif
		}
	}
	if(passtest){
		numPassed++;
		cout << "test 7: test assignment operator"  << endl;
		recCopy = recList;
		intCopy = intList;
		if(!checkList(recCopy,mirror,20)){
			passtest=false;
			cout << "Error 7a: Bug in = operator"  << endl;  		
			#if VERBOSE >= 1
			printLists(recCopy,mirror,20);
			#endif
		}
		if(!checkList(intCopy, intMirror,cap)){
			passtest=false;
			cout << "Error 7b: Bug in = operator"  << endl;  		
			#if VERBOSE >= 2
			printLists(intCopy,intMirror,cap);
			#endif
		}
		duplicateArray(data,mirror,20);
		duplicateArray(intData,intMirror,cap);
	}
	if(passtest){
		numPassed++;
		cout << "test 8: test erase function"  << endl;
		RecentList<Record>::iterator it;
		it=setIterator(recList,19);
		recList.erase(it);
		removeItem(mirror,19,20);
		if(!checkList(recList,mirror,19)){
			passtest=false;
			cout << "Error 8a: Bug in erase." << endl;
			#if VERBOSE >= 1
			printLists(recList,mirror,19);
			#endif
		}
		recList.erase(recList.begin());
		removeItem(mirror,0,19);
		if(!checkList(recList,mirror,18)){
			passtest=false;
			cout << "Error 8b: Bug in remove." << endl;
			#if VERBOSE >= 1
			printLists(recList,mirror,18);
			#endif
		}
		for(int i=0;i<3 && passtest;i++){
			int pick=rand()%(18-i);
			it=setIterator(recList,pick);
			recList.erase(it);
			removeItem(mirror,pick,18-i);
			if(!checkList(recList,mirror,18-i-1)){
				passtest=false;
				cout << "Error 8c:  Bug in erase." << endl;
			}
		}
		intList.erase(intList.begin());
		removeItem(intMirror,0,cap);
		if(!checkList(intList,intMirror,cap-1)){
			passtest=false;
			cout << "Error 8d: Bug in erase." << endl;
		}
		intList.erase(intList.begin());
		removeItem(intMirror,0,cap-1);
		if(!checkList(intList,intMirror,cap-2)){
			passtest=false;
			cout << "Error 8e: Bug in erase." << endl;
		}
		RecentList<int>::iterator it2;
		it2=setIterator(intList,cap-3);
		intList.erase(it2);
		removeItem(intMirror,cap-3,cap-2);
		if(!checkList(intList,intMirror,cap-3)){
			passtest=false;
			cout << "Error 8f: Bug in erase." << endl;
		}
		it2=setIterator(intList,cap-4);
		intList.erase(it2);
		removeItem(intMirror,cap-4,cap-3);
		if(!checkList(intList,intMirror,cap-4)){
			passtest=false;
			cout << "Error 8g: Bug in erase." << endl;
		}
		for(int i=0;i<100 && passtest;i++){
			int pick=rand()%(cap-4-i);
			it2=setIterator(intList,pick);
			intList.erase(it2);
			removeItem(intMirror,pick,cap-4-i);
			if(!checkList(intList,intMirror,cap-i-5)){
				passtest=false;
				cout << "Error 8h:  Bug in erase." << endl;
			}
		}
	}
	if(passtest){
		numPassed++;
		cout << "test 9: test assignment operator (deep copy)"  << endl;
		if(!checkList(recCopy,data,20)){
			passtest=false;
			cout << "Error 9a: Bug in = operator, no deepcopy?"  << endl;
		}
		if(!checkList(intCopy,intData,cap)){
			passtest=false;
			cout << "Error 9b: Bug in = operator,no deep copy?"  << endl;     
		}
	}
	if(passtest){
		numPassed++;
		cout << "test 10: search for removed items" << endl;
		int pick[2]={0,19};
		for(int i=0;i<2;i++){
			auto it =recList.search(data[pick[i]]);
			if(it==recList.end()){
				if(!checkList(recList,mirror,15)){
					passtest=false;
					cout << "Error 10a: Bug in search." << endl;
				}
			}
			else{
				cout << "Error 10b: Bug in search, returned iterator is not correct" << endl;
				passtest=false;
			}
		}

	}
	if(passtest){
		int pick[4]={0,1,cap-1,cap-2};
		for(int i=0;i<4;i++){
			auto it = intList.search(intData[pick[i]]);
			if(it == intList.end()){
				if(!checkList(intList,intMirror,cap-104)){
					passtest=false;
					cout << "Error 10c: Bug in search."<< endl;
				}	
			}
			else{
				passtest=false;
				cout << "Error 10d: Bug in search."<< endl;
			}
		}
	}
	if(passtest){
		numPassed++;
	}
	if(numPassed == 10){
		cout << "Testing for Assignment 1 completed successfully" << endl;
	}
	else{
		cout << numPassed << " / 10 tests passed.  Looks like you still" << endl;
		cout << "have some work to do" << endl;
	}
	return 0;
}
template <typename T>
void adjust(int idx,T arr[]){
	T temp=arr[idx];
	for (int i=idx;i>0 ;i--){
		arr[i]=arr[i-1];
	}/*for*/
	arr[0]=temp;
}
template <typename T>
void removeItem(T arr[],int idx,int sz){
	for(int i=idx;i<sz-1;i++){
		arr[i]=arr[i+1];
	}
}
template <typename T>
bool checkList(const RecentList<T>& list,const T array[],int sz){
	bool rc=true;
	auto it=list.begin();
	int i;
	for(i=0;i<sz && it!=list.end() && rc;i++,it++){
		if(*it != array[i]){
			rc=false;
		}
	}
	if(it!=list.end() || i < sz){
		rc=false;
	}
	return rc;
}

template <typename T>
void duplicateArray(T dest[], const T src[],int sz){
	for(int i=0;i<sz;i++){
		dest[i]=src[i];
	}
}

template <typename T>
void printLists(const RecentList<T>& list,const T array[],int sz){
	auto it=list.begin();
	for(int i=0;i<sz;i++,it++){
		cout << "correct: "  << array[i] << " your list: " << *it << endl;
	}
}
//returns iterator to the idx'th node in the list
template <typename T>
typename RecentList<T>::iterator setIterator(RecentList<T>& list, int idx){
	typename RecentList<T>::iterator it=list.begin();
	for(int i=0;i<idx;i++){
		it++;
	}
	return it;
}