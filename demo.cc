#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the hourglassSum function below.
int hourglassSum(int arr_rows, int arr_columns, int** arr) {
 int highestValue = 0;
 for ( int row = 0; row < arr_rows; )
 {
    for (int col = 0; col < (arr_columns-(arr_columns/3)); col++) {
      bool setMiddle = false;
      int tempValue = 0;
      for (int iCol = col; iCol < 3; iCol++) {
        tempValue = arr[row][iCol] + arr[row + 2][iCol];
        if (!setMiddle) {
          tempValue += arr[row + 1][iCol + 1];
          setMiddle = true;
        }

        if (tempValue > highestValue) {
          highestValue = tempValue;
        }
      }
    }
     row+=3;
 }
 return highestValue;
}

int main()
{

        int arr_rows = 6;
    int arr_columns = 6;
    int **arr = ( int **) malloc(arr_rows *sizeof(int*));
    for( int i =0 ; i< arr_rows; i++)
    {
    	arr[i] = (int*)malloc(arr_columns *sizeof(int));
    }
    
    arr[0][0]=-9;
    arr[0][1]=-9;
    arr[0][2]=-9;
    arr[0][3]=1;
    arr[0][4]=1;
    arr[0][5]=1;
    
    	arr[1][0]=0;
        arr[1][1]=-9;
        arr[1][2]=0;
        arr[1][3]=4;
        arr[1][4]=3;
        arr[1][5]=2;
    
        		arr[2][0]=-9;
                arr[2][1]=-9;
                arr[2][2]=-9;
                arr[2][3]=1;
                arr[2][4]=2;
                arr[2][5]=3;
    
                		arr[3][0]=0;
                        arr[3][1]=0;
                        arr[3][2]=8;
                        arr[3][3]=6;
                        arr[3][4]=6;
                        arr[3][5]=0;
                        
                        		arr[4][0]=0;
                                arr[4][1]=0;
                                arr[4][2]=0;
                                arr[4][3]=-2;
                                arr[4][4]=0;
                                arr[4][5]=0;
                                
                                		arr[5][0]=0;
                                        arr[5][1]=0;
                                        arr[5][2]=1;
                                        arr[5][3]=2;
                                        arr[5][4]=4;
                                        arr[5][5]=0;
                                        
    int result = hourglassSum(arr_rows, arr_columns, arr);

    printf("\n Result: %d", result);

    return 0;
}


