#include <iostream>
using namespace std;

template <typename T>
class DList{
	struct Node{
		T data_;
		Node* next_;
		Node* prev_;
		Node(const T& data,Node* next=nullptr,Node* prev=nullptr){
			data_=data;
			next_=next;
			prev_=prev;
		}
	};
	Node* head_;
	Node* tail_;
public:
	DList(){
		head_=tail_=nullptr;
	}
	void push_front(const T& data){
		//make a node
		Node* nn=new Node(data,head_);
		if(head_!=nullptr){
			head_->prev_=nn;
		}
		else{
			tail_=nn;
		}
		head_=nn;
		
	}
	void push_back(const T& data){
		
	}
	void pop_front(){

	}
	void pop_back(){
		//if list is not empty
		if(head_){
			//if there is more than one node
			if(head_!=tail_){
				tail_=tail->prev_;
				delete tail_->next_;
				tail_->next_=nullptr;
			}
			else{
				delete tail_;
				head_=tail_=nullptr;
			}
		}
	}
	void print() const{
		Node* it=head_;
		while(it!=nullptr){
			cout << it->data_ << endl;
			it=it->next_;
		}
	}
};

