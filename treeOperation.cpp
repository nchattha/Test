#include<iostream>
#include<string>

using namespace std;

template <class Item, class Key>
struct IKPair {  // Item/Key pair
	Item val;
	Key k;
};

template <class Item, class Key>
struct TreeNode{
	IKPair<Item, Key> data;	
	int ht;
	TreeNode *left;
	TreeNode *right;
	TreeNode(IKPair<Item,Key> _data):data(_data),ht(0),left(nullptr),right(nullptr){}
};

template <class Item, class Key>
class BSTree {
	public:
		bool search(const Key& k, Item& returnVal) const;
		bool insert(const Item& v, const Key& k);
		bool remove(const Key& v);
		TreeNode<Item, Key>* getRoot()const;
		BSTree():root(nullptr){}
	private:
		TreeNode<Item, Key> *root;
		//UTIL FUNC
		TreeNode<Item, Key> * insertR( TreeNode<Item, Key> *node, const IKPair<Item,Key> &newNode);
};

template <class Item, class Key>
bool  BSTree< Item, Key>::remove(const Key& v){
	TreeNode<Item, Key> *curr = root;
	while( curr != nullptr )
	{
		if( curr->data.k > k ){//left
			curr = curr->left;
		}
		else if( curr->data.k < k ){//right
			curr = curr->right;
		}
		else
		{
			break;
		}
	}

	if( curr != nullptr )
	{
		//right will be root 
		//In right absence left will be root
		if(curr->right != nullptr)
		{
			TreeNode<Item, Key> *temp = curr->right->left;
			if( temp != nullptr)
			{
				TreeNode<Item, Key> *tempL = curr->left;
				while( tempL->right != nullptr )
					tempL = tempL->right;
				tempL->right = temp;
			}
			//update current right LEFT node to curr left
			curr->right->left = curr->left;
			
			if( curr == root )
				root = curr->right;

			delete curr;
		}
		else
		{//left node will be the ROOT
			root = curr->left;
			delete curr;

		}
		return true;
	}
	return false;
}

template <class Item, class Key>
TreeNode<Item, Key>* BSTree< Item, Key>::getRoot()const{
	return root;
}

template <class Item, class Key>
TreeNode<Item, Key>* BSTree< Item, Key>::insertR(TreeNode<Item, Key> *root, const IKPair<Item,Key> &newNode){

	if( root == nullptr )
	{
		//create Node
		root = new TreeNode<Item,Key>(newNode);
	}
	else
	{
		if( root->data.k < newNode.k)
			root->right = insertR(root->right, newNode);	
		else if( root->data.k > newNode.k)
			root->left = insertR(root->left, newNode);
	}
	return root;	
}	
template <class Item, class Key>
bool BSTree< Item, Key>::insert(const Item& v, const Key& k){
	//create Pair
	IKPair<Item,Key>node = {v,k};
	root = insertR(root, node);
	return true;			
}


//PRINT TREE
#define COUNT 5
	template <class Item, class Key>
void print2DUtil(TreeNode<Item, Key> *root, int space = 0)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->data.val<<","<<root->data.k;

	// Process left child
	print2DUtil(root->left, space);

	cout<<endl;
}


int main(){

	BSTree<string,int> btree;
	btree.insert("n", 15);	
	btree.insert("a", 1);	
	btree.insert("v", 23);	
	btree.insert("d", 4);	
	btree.insert("e", 5);	
	btree.insert("e", 5);	
	btree.insert("p", 17);	
	print2DUtil(btree.getRoot());
	
	btree.remove(17);	
	print2DUtil(btree.getRoot());
	return 0;
}
