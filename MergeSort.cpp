#include<stdlib.h> 
#include<stdio.h> 
  
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k ; 
	int n1 = m-l+1;
	int n2 = r-m;
	
	int arr1[n1], int arr2[n2];
	for( i = 0 ; i < n1 ; i++)
		arr1[i]=arr[l+i];
	for( i = 0 ; i < n2 ; i++)
		arr2[i]=arr[m+1+i];

	i = 0 ; j = 0;
	while ( i < n1 && j < n2 )
	{
		if( arr[i] <= arr[i] ) 
		{
			arr[l] = arr1[i];
			i++;	
		}else
		{
			arr[l] = arr2[j];
                        j++;

		}
		l++;
	}

	while ( i < n1 )
	{
		arr[l] = arr1[i];
		i++;
		l++;
	}
	while ( j < n2 )
	{
		arr[l] = arr2[j];
		j++;
		l++;
	}
}


/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
