
template <typename T>
class Queue{
	T* theQueue_;
	int max_;
	int size_;
	int front_;
	int back_;
	void grow(){
		max_=max_*2;
		T* tmp=new T[max_];
		for(int i=0;i<size_;i++){
			tmp[i]=theQueue_[i];
		}
		delete [] theQueue_;
		theQueue_=tmp;
	}
public:
	Queue(){
		max_=5;
		size_=0;
		front_=0;
		back_=0;
		theQueue_=new T[max_];
	}
	void enqueue(const T& data){

		if(size_==max_){
			grow();
		}	
		theQueue_[back_]=data;
		back_++;
		if(back_==max_){
			back_=0;
		}
		// alternatively: back_=(back_+1)%max_;
		// another alternative: back=(back_+1 == max_)?0:back_+1;
		size_++;	
	}
	void dequeue(){
		if(size_ >  0){
			front_++;
			if(front_==max_){
				front_=0;
			}
			size_--;
		}
	}
	T front(){
		return theQueue_[front_];
	}
};