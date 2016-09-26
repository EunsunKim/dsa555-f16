#include <iostream>
using namespace std;

template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data=T{},Node* next=nullptr,Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* head_;
	Node* tail_;
public:
	DList(){
		head_=new Node();  //head sentinel
		tail_=new Node();  //tail sentinel
		head_->next_=tail_;
		tail_->prev_=head_;
	}
	void push_front(const T& data){
		//head_ points to the front sentinel, so
		//the node that follows is the first node
		//in the linked list.  If that first node
		//is tail_ then the list is empty.
		Node* first=head_->next_;
		//make a node
		Node* nn=new Node(data,first,head_);
		head_->next_=nn;
		first->prev_=nn;		
		
	}
	void push_back(const T& data);
	void pop_front();
	void pop_back(){
		//check if list is empty
		if(){
			//unlink last data node 
			//delete last data node
		}


	}
	void print() const{

	}
};

