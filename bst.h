class BST{

	struct Node{
		int data_;
		Node* left_;
		Node* right_;
		Node(int v,Node* l=nullptr, Node* r=nullptr){
			data_=v;
			left_=l;
			right_=r;
		}
	};
	Node* root_;	
	//insert v into the subtree with root
	//subtreeroot
	void ins(v, subtreeroot);
public:
	BST(){
		root_=nullptr;
	}
	void insRecursive(int v){
		ins(v, root_);
	}
	void insert(int v){
		if(root_==nullptr){
			root_=new Node(v);
		}
		else{
			Node* curr=root_;
			while(){
				if(data < curr->data){
					//go left
				}
				else{
					//go right
				}
			}

		}
	}
	void remove(int v);
	void print() const;
	~BST();
}