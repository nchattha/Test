#include<iostream>
using namespace std;

int search(int *arr, int size)
{
	int a = 0, b = size-1;
	int mid = 0;
	// subtract the index with value to get diffrence it should be same for every indexes
	// If not - there is missing number. Accordingly, move to Left or roght of mid
	// 
	while( b -a > 1 )
	{
		mid = (a+b)/2;
		if ( (arr[a] -a) != (arr[mid] - mid ))
			b = mid;
			
		else if ( (arr[b] -b) != (arr[mid] - mid ))
			a = mid;
	}
	return (arr[mid]+1);
}

int main(){

	int a[] = {1,3};
	cout<<search(a,2)<<endl;


	return 0;
}
