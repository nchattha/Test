// CPP program to test 
// size of struct 
#include <iostream> 
using namespace std; 

// first structure 
struct test1 
{ 
	char e; 
	int i; 
}; 

// second structure 
struct test2 
{ 
	short int i; 
	char c1; 
	char c2; 
	char c3; 
	//short int i; 
}; 

// driver program 
int main() 
{ 
	test1 t1; 
	test2 t2; 
	cout << "size of struct test1 is " << sizeof(t1) << "\n"; 
	cout << "size of struct test2 is " << sizeof(t2) << "\n"; 
	return 0; 
} 

