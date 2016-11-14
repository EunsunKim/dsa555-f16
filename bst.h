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
	void ins(int v,Node*& subtreeroot){
		if(subtreeroot==nullptr){
			subtreeroot=new Node(v);
		}
		else{
			if(v < subtreeroot->data_){
				ins(v,subtreeroot->left_);
			}
			else{
				ins(v,subtreeroot->right_);
			}
		}
	}
	//this function prints the tree with root at address
	//subtreeroot
	void printInorder(const Node* subtreeroot) const {
		if(subtreeroot!=nullptr){
			printInorder(subtreeroot->left_);
			cout << subtreeroot->data_ << endl;
			printInorder(subtreeroot->right_);
		}
	}
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
			bool isInserted=false;
			while(!isInserted){
				if(data < curr->data_){
					if(curr->left_ != nullptr){
						curr=curr->left_;
					}
					else{
						curr->left_=new Node(v);
						isInserted=true;						
					}

				}
				else{
					//go right
					if(curr->right_ != nullptr){
						curr=curr->right_;
					}
					else{
						curr->right_=new Node(v);
						isInserted=true;
					}
				}
			}
		}
	}
	void remove(int v);
	void print() const{

	}
	~BST();
}