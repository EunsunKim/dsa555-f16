#include "fulllist.h"
template <typename T>
class Stack{
	DList<T> theStack_;
public:
	Stack(){}
	void push(const T& data){
		theStack_.push_front(data);
	}
	void pop(){
		theStack_.pop_front();	

	}
	T top(){
		DList<T>::iterator it= theStack_.begin();
		return *it
	}
};