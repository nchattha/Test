#include<iostream>
#include<string>
using namespace std;

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
	node(int _freq):freq(_freq){ left = nullptr; right = nullptr; }
	node(int _freq, char _data):freq(_freq),data(_data){ left = nullptr; right = nullptr; }
    
} node;





void decode_huff(node * root, string s){
 int index = 0;

	node *curr = root;
	cout<< s.size()<<endl;
	while( index <= s.size() && curr != nullptr)
	{
		if( curr->left == nullptr && curr->right == nullptr )
		{
			cout<<curr->data;
			curr = root;	
		}
		if( s[index] == '0' )
		{
			curr = curr->left;
		}
		else if ( s[index] == '1' )
		{
			curr = curr->right;	
		}
		index++;	
	}
	cout<<endl;
}

int main(){

node *root = new node(5);
root->right = new node(3,'a');
root->left = new node(2);
root->left->left = new node(1,'b');
root->left->right = new node(1,'c');

string s = "1001011";
decode_huff(root,s);

return 0;

}
