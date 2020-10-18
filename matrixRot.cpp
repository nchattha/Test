// CPP program to test 
// size of struct 
#include <iostream> 
using namespace std; 
const int R = 4;
const int C = 4;
void reverseArray(int arr[][C], int row, int col)
{
	int prev = 0, cur = 0, r = 0, c = 0;

	//for ( int r = 0, c =0; r < row && c < col ; )
	{
		prev = arr[r+1][c];
		for ( int i = c ; i < col ; i++)
		{
			cur = arr[r][i];
			arr[r][i] = prev; 
			prev = cur;
		}
		r++;
          	
		for ( int i = r ; i < row ; i++)
		{
			cur = arr[i][col-1];
			arr[i][col-1] = prev; 
			prev = cur;
			cout<<i<<" : "<< col-1<< "["<<cur<<","<<prev<<"]"<<endl;	
		}
		col--;

		if( r < row){
			for ( int i = col-1 ; i >= c ; i--)
			{
				cur = arr[row-1][i];
				arr[row-1][i] = prev; 
				prev = cur;
			}
		}
		row--;

		if( c < col){
			for ( int i = row-1 ; i >= r ; i--)
			{
				cur = arr[i][c];
				arr[i][c] = prev; 
				prev = cur;
			}
		}
		c++;

	} 
}


int main() 
{ 
	int array[R][C]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	reverseArray(array,R,C);
	cout<<endl;
	for ( int i = 0  ; i < R ; i++ )
	{	for ( int j = 0  ; j < C ; j++ )
		{
			cout<<"\t"<<array[i][j];
		}
		cout<<endl;
	}	
	return 0; 
} 

