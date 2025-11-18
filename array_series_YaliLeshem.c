/*------------------------------------------------------
* Filename: array_series_YaliLeshem.c
* Description: find for int array with 15 numbers if it's increasing, decreasing, constant or messed up
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

#define CONST_LEN 15


/*------------------------------------------------------
* Function Name - findArray
*
* Function Purpose - Finds order of elements in array, if exists
*
* Parameters –  Int array of 15 elements, and size of that array
*
*
* Author - Yali Leshem
-------------------------------------------------------*/

void findArray(int arr[], int size)
{
    int index, increase = 1, decrease = 1, constant = 1;
    // starting from second element because need to look one index back for each iteration
    for (index = 1; index < size; index++)
    {
        // If order is kept, ensure only increase value stays one. If not, it'd be messed up.
        if (arr[index] > arr[index-1]) {
            decrease = 0;
            constant = 0;
        }
        else if (arr[index] < arr[index-1]) {
            increase = 0;
            constant = 0;
        }
        else if (arr[index] == arr[index-1]) {
            increase = 0;
            decrease = 0;
        }
    }

    if (increase)
        printf("The array is increasing\n");
    else if (decrease)
        printf("The array is decreasing\n");
    else if (constant)
        printf("The array is constant\n");
    else
        printf("The array is messed up\n");
}

int main() {

    int i, arr[CONST_LEN];
    printf("Insert 15 numbers into array: \n");

    for (i = 0; i < CONST_LEN; i++) {
        if (scanf("%d",&arr[i]) == -1) { // in case the input wasn't a number, exit program
            printf("Input invalid, leaving program \n");
            return 1;
        }

    }

    findArray(arr, CONST_LEN);

    return 0;
}