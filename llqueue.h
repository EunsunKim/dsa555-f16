#include "fulllist.h"
template <typename T>
class Queue{
	DList<T> theQueue_;
public:
	Queue(){}
	void enqueue(const T& data){
		theQueue_.push_back(data);
	}
	void dequeue(){
		theQueue_.pop_front();	

	}
	T front(){
		DList<T>::iterator it= theQueue_.begin();
		return *it
	}
};