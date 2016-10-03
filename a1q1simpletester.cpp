//g++ -std=c++0x a1q1simpletester.cpp


#include "a1q1.h"
#include <iostream>
using namespace std;
int main(void){
	RecentList<int> list;
	list.insert(10);
	list.insert(20);
	list.insert(30);

	RecentList<int>::iterator it=list.begin();
	for(;it != list.end();++it){
		cout << *it << endl;
	}
	cout << "****"<< endl;

	do{
		it--;
		cout << *it << endl;
	}while(it!=list.begin());
	cout << "****"<< endl;

	for(;it != list.end();it++){
		cout << *it << endl;
	}


}