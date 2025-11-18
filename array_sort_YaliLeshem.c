/*------------------------------------------------------
* Filename: array_sort_YaliLeshem.c
* Description: Sort the array of pointers to the integers in order
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

#define ARRAY_LEN 10


/*------------------------------------------------------
* Function Name - swap
*
* Function Purpose - Recieving two pointers *addresses* (In case of misorder while sorting) so could swap their address and content completely
*
* Parameters –  Int ** first and int ** second - two pointers given by their addresses
*
-------------------------------------------------------*/

void swap(int **first, int **second) { // swap the pointers themselves (by the address of the pointers, this is why must pass '**')
    int *temp = *first;
    *first = *second;
    *second = temp;
}


/*------------------------------------------------------
* Function Name - sort_pointers
*
* Function Purpose - Sort the integers by their values, using bubble sort
*
* Parameters –  Int *pointers_arr[], array of int pointers to values in integers array.
*
-------------------------------------------------------*/

void sort_pointers(int *pointers_arr[]) {
    int i, j;

    for (i = 0; i < ARRAY_LEN - 1; i++) {
        for (j = 0; j < ARRAY_LEN - i - 1; j++) { // Implementing bubble sort
            if (*pointers_arr[j] > *pointers_arr[j + 1]) {
                swap(&pointers_arr[j], &pointers_arr[j + 1]); // If two pointers' values are misordered, swap between them
            }
        }
    }
}

int main() {
    int index, integers_arr[ARRAY_LEN];
    int *pointers_arr[ARRAY_LEN];

    printf("Enter %d integers to array of integers: \n", ARRAY_LEN);
    for (index = 0; index < ARRAY_LEN; index++) {
        if (scanf(" %d", &integers_arr[index]) != 1) { // In case input is invalid
            printf("Bad input, not an integer. Exiting program \n");
            return 1;
        }
    }

    for (index = 0; index < ARRAY_LEN; index++) // Initialize the pointers array to point to integers (random order currently)
        pointers_arr[index] = &integers_arr[index];

    for (index = 0; index < ARRAY_LEN; index++)
        printf("Address of the %d-th pointer is: %p and value: %d \n", index+1, (void*)pointers_arr[index], *pointers_arr[index]);
    printf("\n");

    sort_pointers(pointers_arr); // sort the integers array in right order

    for (index = 0; index < ARRAY_LEN; index++)
        printf("Address of the %d-th pointer is: %p and value: %d \n", index+1, (void*)pointers_arr[index], *pointers_arr[index]);

    return 0;
}