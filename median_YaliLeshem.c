/*------------------------------------------------------
* Filename: median_YaliLeshem.c
* Description: recieve an unknown amount of integers into memory and calculate their median value
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1

void swap(int *p1, int *p2) {
    // recieve p1 and p2 addresses in memory to swap between their contents
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/*------------------------------------------------------
* Function Name - read_integers
*
* Function Purpose - Use realloc to recieve an unknown number of integers
*
* Parameters – **listnums - an address of a pointer to the list of numbers inserted by user, 
* *total_count - used to alter the count of how many elements has the user inputted
*
* Return value - read_integers returns 0 for success and 1 for failure.
*
-------------------------------------------------------*/
int read_integers(int **list_nums, int *total_count) {
    int input, count = 0, *numbers = NULL;

    printf("enter integers: \n");
    while (scanf(" %d", &input) == 1) {
        int *next_int = (int *)realloc(numbers, (count + 1) * sizeof(int)); // each time use realloc for the next integer compartment
        
        if (next_int == NULL) {
            printf("dynamic memory allocation failed \n");
            free(numbers); // if dynamic memory failed, free the used ones and exit function
            return FAILURE;
        }
        
        numbers = next_int; // points to new beginning of memory
        *(numbers + count) = input; // store into memory the next integer
        count++;
    }

    *list_nums = numbers; // keep the numbers entered and their count values, in their addresses
    *total_count = count;
    return SUCCESS;
}

// using selection sort algorithm for all integers in memory by going over iteratively
void selection_sort(int *nums, int count) {
    int i, j;

    for (i = 0; i < count; i++) {
        for (j = i+1; j < count; j++) { // No need to sort the already sorted 0-i indexes. 
            if (*(nums + i) > *(nums + j)) {
                swap((nums + i), (nums + j)); // if two elements are in wrong order, swap between them, by their addresses
            }
        }
    }
}

int main() {
    int index, count = 0, *numbers = NULL;
    
    if (read_integers(&numbers, &count) != 0) {
        // If an error was found during memory allocation - return and stop immediately the run
        return FAILURE;
    }

    if (count == 0) {
        printf("No number entered so median isn't avaliable \n");
        return FAILURE;
    }

    selection_sort(numbers, count); // Sort the element
    printf("all numbers, sorted: ");
    
    for (index = count-1; index > -1; index--) // print sorted numbers
        printf("%d ", *(numbers + index));
    printf("\n");

    double median;
    int mid_point = count / 2;

    if (count % 2 != 0)
        median = (double) *(numbers + mid_point); // the middle element is the median in case of odd-lengthed sorted sequence
    else
        median = ((double) *(numbers + (mid_point - 1)) + *(numbers + mid_point)) / 2; // median in even-lengthed sorted sequence is a[(mid-1)/2]+a[mid/2] / 2
        
    printf("median is: %f \n", median);

    free(numbers); // free the used memory from dynamic allocation
    
    return SUCCESS;

}

