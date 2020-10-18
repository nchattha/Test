// CPP program to test 
// size of struct 
#include <iostream> 
using namespace std; 

int reverseArray(int number)
{
	if( number ==  0 )
		return 0;

	reverseArray(--number);

}


int main() 
{ 
	cout<<endl;
	cout<<"Number : "<<reverseArray(5);
	cout<<endl;
	return 0; 
} 

