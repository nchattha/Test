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
	
	if( rootNode->key < value )
	{
		insert( rootNode->right, value);
	}
	else
	{
		insert( rootNode->left, value);
	}
}

bool search( Node *&rootNode, int value)
{
	bool status = false;

	if( !rootNode)	
	{
		return false;
	}
	else if( rootNode->key == value )
        {
                return true;
        }

        if( rootNode->key < value )
        {
               status = search( rootNode->right, value);
        }
        else
        {
                status = search( rootNode->left, value);
        }

	return status;
}
void printInorder( Node *&rootNode)
{
	if( !rootNode)
		return;

	printInorder(rootNode->left);
	cout<<rootNode->key<<" ";
	printInorder(rootNode->right);
}

int main()
{
	Node *root = NULL ;
	insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	cout<<endl;	
	printInorder(root);
	cout<<endl;
	int value = 80;	
	cout<<value<<" value search status: "<<search(root, value)<< endl;	
	cout<<endl;	
	return 0;

}
