

template <typename T>
class AVL{
	struct Node{
		T data_;
		Node* left_;
		Node* right_;
		int height_;     //this is the height of this
		                 //nodes subtree. 
		Node(const T data){
			data_=data;
			left_=right_=nullptr;
			height_=1;
		}
	};
	int height(const Node* n) const{
		int rc;
		if(n == nullptr){
			rc=0
		}
		else{
			rc=n->height_;
		}
		return rc;
	}
	int balance(const Node* n) const{
		int rc;
		if(n == nullptr){
			rc=0
		}
		else{
			rc=height(n->right_) - height(n->left_);
		}
		return rc;
	}
	void leftRotate(Node*& A){
		Node* B = A->right_;
		Node* y = B->left_;
		A->right_=y;
		B->left_=A;
		A=B;
				
	}
	void rightRotate(Node*& A){
		
	}

	insert(Node*& r,const T data){
		if( r == nullptr){
			r=new Node(data);
		}
		else{
			int heightLeft;
			int heightRight;
			if(data < r->data){
				insert(r->left_ , data);

			}
			else{
				insert(r->right_,data);
			}
			heightLeft=height(r->left_);
			heightRight=height(r->right_);
			height_=1 + ((heightRight>heightLeft)?heightRight:heightLeft);
			if(balance(r) == 2){
				if(balance(r->right_) == 1){
					leftRotate(r);
				}
				else{

					rightRotate(r->right_)
					leftRotate(r);
					//double rotation
				}
			}
			else if(balance(r)== -2){
				if(balance(r->left_) == -1){
					//single rotation
				}
				else{
					//double rotation
				}			
			}

		}

	}
public: 
	AVL();
	void insert(const T& data){
		insert(root_,data);
	}
	void print() const;
	~AVL();
}