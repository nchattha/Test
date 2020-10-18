#include <iostream> 
#include <queue> 
using namespace std; 
  
/* A binary tree node has key, pointer to left child 
and a pointer to right child */
struct Node { 
    int key; 
    struct Node* left, *right; 
}; 
  
/* function to create a new node of tree and r 
   eturns pointer */
struct Node* newNode(int key) 
{
    struct Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
};

void insert( Node *&rootNode, int value)
{
	if( !rootNode )
	{	
		rootNode = newNode(value);
		cout<<"\n"<<value<<": Node Created"<<rootNode; 
		return; 
	}	
	
	if( rootNode->left && !rootNode->right)
	{
		insert( rootNode->right, value);
//		cout<<" RIGHT with Parent: "<<rootNode->key; 
	}
	else
	{
		insert( rootNode->left, value);
//		cout<<" LEFT with Parent: "<<rootNode->key; 
	}
}

void printBFSOrder( Node *&rootNode, bool root = false)
{
 
       if( !rootNode)
                return;

	if(root)
        cout<<rootNode->key<<" ";
        if(rootNode->left)
	cout<<rootNode->left->key<<" ";
        if( rootNode->right)
	cout<<rootNode->right->key<<" ";
        printBFSOrder(rootNode->left);
        printBFSOrder(rootNode->right);
}

void printInorder( Node *&rootNode)
{
	if( !rootNode)
		return;

	printInorder(rootNode->left);
	cout<<rootNode->key<<" ";
	printInorder(rootNode->right);
}
void printPostOrder( Node *&rootNode)
{
	if( !rootNode)
		return;

	printPostOrder(rootNode->left);
	printPostOrder(rootNode->right);
	cout<<rootNode->key<<" ";
}
void printPreOrder( Node *&rootNode)
{
	if( !rootNode)
		return;

	cout<<rootNode->key<<" ";
	printPreOrder(rootNode->left);
	printPreOrder(rootNode->right);
}
int main()
{
	Node *root = NULL ;
	insert(root,1);
	insert(root,2);
	insert(root,3);
	insert(root,4);
	insert(root,5);
	cout<<endl;	
	printInorder(root);
	cout<<endl;	
	printPreOrder(root);
	cout<<endl;	
	printPostOrder(root);
	cout<<endl;	
	printBFSOrder(root,true);	
	return 0;

}
