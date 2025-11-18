#include <stdio.h>
#include <stdlib.h>

void swap(int *p1, int *p2) {
    // recieve p1 and p2 addresses in memory to swap between their contents
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int read_data(int **list_nums, int *total_count) {
    int input, count = 0, *numbers = NULL;

    printf("enter integers: \n");
    while (scanf(" %d", &input) == 1) {
        int *next_int = (int *)realloc(numbers, (count + 1) * sizeof(int)); // each time use realloc for the next integer compartment
        
        if (next_int == NULL) {
            printf("dynamic memory allocation failed \n");
            free(numbers); // if dynamic memory failed, free the used ones and exit function
            return 1;
        }
        
        numbers = next_int; // points to beginning of memory
        *(numbers + count) = input; // store into memory the next integer
        count++;
    }

    *list_nums = numbers; // keep the numbers entered and their count values, in their addresses
    *total_count = count;
    return 0;
}

void bubble_sort(int *nums, int count) {
    int i, j;

    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) { // using bubble sort algorithm for all integers in memory by going over until count
            if (*(nums + i) > *(nums + j)) {
                swap((nums + i), (nums + j)); // if two elements are in wrong order, swap between them, by their addresses
            }
        }
    }
}

int main() {
    int index, count = 0, *numbers = NULL;
    
    if (read_data(&numbers, &count) != 0) {
        // If an error was found during memory allocation - return and stop immediately the run
        return 1;
    }
    
    bubble_sort(numbers, count);

    if (count == 0) {
        printf("No number entered so median isn't avaliable \n");
        return 1;
    }

    printf("all numbers, sorted: ");
    if (count > 0) {
        for (int index = count-1; index > -1; index--) {
            printf("%d ", *(numbers + index));
        }
    }
    printf("\n");

    double median;
    int mid_point = count / 2;

    if (count % 2 != 0)
        median = (double)*(numbers + mid_point); // the middle element is the median in case of odd-lengthed sorted sequence
    else
        median = ((double) *(numbers + (mid_point - 1)) + *(numbers + mid_point)) / 2.0; // median in even-lengthed sorted sequence is a[(mid-1)/2]+a[mid/2] / 2
        
    printf("Median is: %f \n", median);

    free(numbers); // free all used memory from dynamic allocation
    
    return 0;
}