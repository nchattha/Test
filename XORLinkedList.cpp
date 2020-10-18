#include<stdio.h>
#include<stdint.h>
#include<iostream>

using namespace std;

class Node{
	public:	int data;
	public: Node* xorNode;
};

Node* XOR( Node* a, Node*b)
{
	return (Node *)((uintptr_t)a^(uintptr_t)b);
}

void insert(Node *&node, int data)
{
	Node *nNode = new Node();
	nNode->data = data;
	nNode->xorNode = XOR(node, NULL);

	if( node )
	{
		node->xorNode = XOR( nNode, node->xorNode);
	}
	node = nNode;
}
void printList (Node *head)  
{  
    Node *curr = head;  
    Node *prev = NULL;  
    Node *next;  
  
    cout << "Following are the nodes of Linked List: \n";  
  
    while (curr != NULL)  
    {  
        // print current node  
        cout<<curr->data<<" ";  
  
        // get address of next node: curr->npx is  
        next = XOR (prev, curr->xorNode);  
  
        // update prev and curr for next iteration  
        prev = curr;  
        curr = next;  
    }  
}

int main()
{
	Node *head = NULL;  
	insert(head, 10);  
	
	Node *root = head;  
	insert(head, 20);  
	insert(head, 30);  
	insert(head, 40);  

	// print the created list  
	printList (root);
	return 0;
}
