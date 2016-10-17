
template <typename T>
class Stack{
	T* theStack_;
	int max_;
	int size_;
	void grow(){
		max_=max_*2;
		T* tmp=new T[max_];
		for(int i=0;i<size_;i++){
			tmp[i]=theStack_[i];
		}
		delete [] theStack_;
		theStack_=tmp;
	}
public:
	Stack(){
		max_=5;
		size_=0;
		theStack_=new T[max_];
	}
	void push(const T& data){

		if(size_==max_){
			grow();
		}	
		theStack_[size_++]=data;
	
	}
	void pop(){
		if(size_ >  0){
			size_--;
		}
	}
	T top(){
		return theStack_[size_-1];
	}
};