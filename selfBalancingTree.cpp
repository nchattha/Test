#include<iostream>
using namespace std;

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
    int bf;
    node(int _val):val(_val), left(nullptr), right(nullptr), ht(0){}	
} node; 


int maxVal(int left, int right)
{
	return left>right?left:right;
}

int getHeight( node *curr  )
{
	if ( curr != nullptr    )
	{
		cout<<curr->val<<" :: "<<curr->ht<<endl;
		return curr->ht ;
	}
	return -1;
}

int getBalance( node *root)
{
	if( root == nullptr)
		return 0;
	return getHeight(root->left)-getHeight(root->right);
}

node *rotateL(node *root)
{
	//taking care of left node and left right node
	node *x = root->right;
	node *xL = x->left;
	//do the shift
	x->left = root; //root will become the left child
	root->right = xL; // root right will become xL
	//update the height;
	//getting the ht
	root->ht = 1+maxVal(getHeight(root->left),getHeight(root->right));
	x->ht = 1+maxVal(getHeight(x->left),getHeight(x->right));

      	cout<<x->val<<" LLLLLLLL:: "<<x->ht<<endl; 
	return x;
}

node *rotateR(node *root)
{
	//taking care of left node and left right node
	node *x = root->left;
	node *xR = x->right;
	//do the shift
	x->right = root; //root will become the child
	root->left = xR; // root left will become xR
	//update the height;
	//getting the ht
	root->ht = 1+maxVal(getHeight(root->left),getHeight(root->right));
	x->ht = 1+maxVal(getHeight(x->left),getHeight(x->right));
	return x;
}	
node * insert(node * root,int val)
{
	node *currNode = root;

	if( currNode == nullptr ) return new node(val);
	if( val < currNode->val ) 
		currNode->left = insert(currNode->left,val);	 
	else if( val > currNode->val ) 
		currNode->right = insert(currNode->right,val);	 

	//getting the ht
	currNode->ht = 1+maxVal(getHeight(currNode->left),getHeight(currNode->right));
	//cout<<currNode->val<<" : "<<currNode->ht<<":: "<<getHeight(currNode->left)<<":: "<<getHeight(currNode->right)<<endl;
	//balance factor 
	int bf = getBalance(currNode); 

	// check for LL case
	if( bf > 1 &&  val < currNode->left->val ) 	
	{		cout<<currNode->val<<" : "<<bf<<"LL"<<endl;
		return rotateR(currNode);
}

	// check for LR case
	if( bf > 1 &&  val > currNode->left->val ) 	
	{
		cout<<currNode->val<<" : "<<bf<<"LR"<<endl;
		currNode->left = rotateL(currNode->left);
		return rotateR(currNode);
	}
	// check for RR case
	if( bf < -1 &&  val > currNode->right->val ) 	
	{
		cout<<currNode->val<<" : "<<bf<<"RR"<<val<<endl;
		return rotateL(currNode);
	}// check for RL case
	if( bf < -1 &&  val < currNode->right->val ) 	
	{
		cout<<currNode->val<<" : "<<bf<<"RL"<<endl;
		currNode->right = rotateR(currNode->right);
		return rotateL(currNode);
	}

	root = currNode;
	return root;

}

#define COUNT 8
void print2DUtil(node *root, int space)
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
	cout << root->val<<","<<root->ht<<","<<root->bf;

	// Process left child
	print2DUtil(root->left, space);
}

int main()
{
	node *root = insert(nullptr,3);
	root = insert( root,2);
	root = insert( root,4);
	root = insert( root,5);
	root = insert( root,6);
	print2DUtil(root,0);	
	cout<<endl;
	return 0;
}
