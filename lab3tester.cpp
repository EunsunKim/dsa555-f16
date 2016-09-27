#include "dlist.h"
int main(void){
	DList<int> list;
	SList<int> list2;
	list.push_front(10);
	list.print();    //15
	cout << "*****1******" << endl;
	list.push_front(5);
	list.push_front(15);
	list.print();    //15 5 10
	cout << "*****2******" << endl;
	list.pop_back();
	list.print();   //15 5
	cout << "*****3******" << endl;
	list.pop_back();
	list.pop_back();
	list.print();  //list is empty (should print nothing)
	cout << "*****4******" << endl;
	list.push_back(1);
	list.print();   //1
	cout << "*****5******" << endl;
	list.push_back(2);
	list.push_back(3);
	list.print();   //1 2 3 
	cout << "*****6******" << endl;
	list.pop_front();
	list.print();   //2 3 
	cout << "*****7******" << endl;
	list.pop_front();
	list.pop_front();
	list.print();   //prints nothing, list is empty 
	cout << "*****8******" << endl;
	list.push_back(20);
	list.push_front(21);
	list.push_back(22);
	list.push_front(23);
	list.print();  //prints: 23 21 20 22 
}
