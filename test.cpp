#include<stdio.h>
#include<iostream>
using namespace std;

int minimumSwaps(int arr_count, int* arr) {

    int count = 0 ;
    for ( int i = 0 ; i < arr_count-1 ; i++)
    {
      for (int j = 0 ; j < arr_count-i-1; j++)
      {
          if( arr[j] > arr[j+1] )
          {
            int temp = arr[i] + arr[j];
            arr[i] = temp-arr[i];
            arr[j] = temp-arr[i];
            count++;
          }
      }
    }
    cout<<endl;
    for ( int i = 0 ; i < arr_count ; i++)
    {
	cout<<arr[i]<<" : ";
    }
    cout<<endl;
    return count;
}

int main()
{
	int array[5] = {2,3,4,1,5};
	int count = minimumSwaps(5,array);
	cout<< "Count : "<<count<<endl;

	string a = "236";
	string b = "az0";
cout<<"==========="<<endl;
if( a.compare(b) < 0 )
{ cout<<a<<endl;
}else
{ cout<<b<<endl;
}


	return 0;
}
