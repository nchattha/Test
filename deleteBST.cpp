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

Node* findNodeMinValue(Node *&node)
{
	if( node && !node->left )
	 return node;

	if( node && node->left )
	 return findNodeMinValue(node->left);		
	
	return NULL;
}

Node* deleteBR( Node *&rootNode, int value)
{
	if( !rootNode ) return rootNode;

	if( value < rootNode->key )
		rootNode->left = deleteBR( rootNode->left, value); 
	else if( value > rootNode->key )
		rootNode->right = deleteBR( rootNode->right, value);
	else
	{
		// node delete is leaf
		if( !rootNode->left && !rootNode->right )
		{
			free(rootNode);
			rootNode = NULL;
			return NULL;
		}	 
		else if ( !rootNode->left )
		{
			Node *temp = rootNode->right;
			free(rootNode);
			rootNode = NULL;	
			return temp;
		}
		else if ( !rootNode->right )
		{
			Node *temp = rootNode->left;
			free(rootNode);
			rootNode = NULL;	
			return temp;
		}
		//find the min. value 
		Node *temp = findNodeMinValue(rootNode->right);
		if ( temp )
		{
			rootNode->key = temp->key;
			rootNode->right = deleteBR( rootNode->right, temp->key);	
		}
	}
	return rootNode;
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
	int value = 50;	
	cout<<value<<" value delete status: "<<deleteBR(root, value)<< endl;	
	cout<<endl;	
	cout<<endl;	
	printInorder(root);
	return 0;

}
