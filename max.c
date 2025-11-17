/*------------------------------------------------------
* Filename: max.c
* Description: Finding the maximum out of three numbers in just 4 lines
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

int main () {
    int x = 5;
    int y = 7;
    int z = y * (x+y >= 2*x) + x * (x+y > 2*y); // If x+y >= 2x then y > x, otherwise x > y.
    printf("The max numebr is %d \n", z);
}