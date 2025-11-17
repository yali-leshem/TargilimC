/*------------------------------------------------------
* Filename: num_sum_YaliLeshem.c
* Description: Check for a sequence of numbers if the first and last elements equal to the rest
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

int main () {
    int sum_first_last = 0, sum_rest = 0, curr_num, last_num;
    
    printf("Enter sequence of numbers: \n");

    scanf("%d", &curr_num);
    sum_first_last += curr_num; // Receive first number in sequence.

    while (1) {
        if (scanf("%d", &curr_num) != 1) { // end of sequence
            printf("Reached end of input \n");
            break;
        }
        
        last_num = curr_num; // save for next iteration the curr num as well
        sum_rest += curr_num; // summing over rest of numbers only
    } 

    sum_rest -= last_num;
    sum_first_last += last_num; // Making sure sum of first and last consists of both, while the rest aren't

    if (sum_first_last == sum_rest)
        printf("The sum is equal \n");
    else
        printf("The sum isn't equal \n");
    
    return 0;
}
