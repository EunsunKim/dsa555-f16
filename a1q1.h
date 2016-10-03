template <class T>
class RecentList{
	struct Node{
		Node(const T& data=T{},Node* next=nullptr, Node* prev=nullptr){

		}
	};
public:
	class const_iterator{
	protected:
	public:

		bool operator==(const_iterator right){
		}
		bool operator!=(const_iterator right){
		}
		const_iterator(){

		}
		const_iterator operator++(){

		}
		const_iterator operator--(){

		}
		const_iterator operator++(int){

		}
		const_iterator operator--(int){

		}
		const T& operator*() const{

		}
	};
	class iterator:public const_iterator{
	public:
		iterator(){
			
		}
		iterator operator++(){

		}
		iterator operator--(){

		}
		iterator operator++(int){

		}
		iterator operator--(int){

		}
		const T& operator*() const{

		}
		T& operator*(){

		}
	};
	RecentList(){

	}
	iterator begin(){

	}
	const_iterator begin() const{

	}
	iterator end(){

	}
	const_iterator end() const{

	}
	void insert(const T& data){

	}
	void remove(const T& data){

	}
	const_iterator search(const T& key){

	}
	iterator search(const T& key){

	}
	~RecentList(){

	}
	RecentList(const RecentList& rhs){

	}
	RecentList(RecentList&& rhs){

	}
	RecentList& operator=(const RecentList& rhs){

	}
	RecentList& operator=(RecentList&& rhs){

	}
};
