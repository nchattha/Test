// CPP program to test 
// size of struct 
#include <iostream> 
using namespace std; 

void reverseArray(int arr[], int start, int end)
{
	if( start < end ){
		int temp = arr[end];
		arr[end] = arr[start];
		arr[start] =temp;	
	}
	else
		return;

	reverseArray(arr,start+1,end-1);

}


int main() 
{ 
	int array[5]={1,2,3,4,5};
	reverseArray(array,0,5-1);
	cout<<endl;
	for ( int i = 0  ; i < 5 ; i++ )
	{
		cout<<"\t"<<array[i];
	}
	cout<<endl;
	return 0; 
} 

