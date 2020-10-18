#include<iostream>

using namespace std;
typedef struct node{
	int val;
	node *next;
	node(int _val):val(_val){ next = nullptr;}
}node;


node* reverseLinkedList(node *root)
{
	node *curr, *prev , *next;
	
	curr = root;
	prev = next = nullptr;
	while( curr != nullptr)
	{
		next = curr->next; 
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	root = prev;
	return root;
}

bool checkLoop(node *root)
{
	node *slow, *fast;
	slow = fast = root;

	while( fast != nullptr && fast->next != nullptr )
	{
		slow = slow->next;
		fast = fast->next->next;
		if( slow == fast )
			return true;

	}
	return false;
}

node* checkLoopN(node *root)
{
	node *slow, *fast;
	slow = fast = root;
	bool status = false;
	while( fast != nullptr && fast->next != nullptr )
	{
		slow = slow->next;
		fast = fast->next->next;
		if( slow == fast )
		{
		       status = true;
			break;
		}

	}

	if( !status ) return nullptr;
	slow = root;
	while ( slow != fast )
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}


void printD(node *root)
{
	while( root != nullptr)
	{
		cout<<root->val<<"->";
		root=root->next;
	}
		cout<<"NULL"<<endl;
}
	

int main()
{
	node *root = new node(1);
	root->next = new node(2);
	root->next->next = new node(3);
	root->next->next->next = new node(4);
	root->next->next->next->next = new node(5);
	printD(root);
	root = reverseLinkedList(root);
	printD(root);
	node *root1 = new node(1);
	root1->next = new node(2);
	root1->next->next = new node(3);
	root1->next->next->next = new node(4);
	root1->next->next->next->next = root1->next;
	cout<<checkLoopN(root1)->val<<endl;
	return 0;
}
