/*------------------------------------------------------
* Filename: max.c
* Description: Finding the maximum out of two numbers in just 4 lines
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

int main () {
    int x = 5;
    int y = 7;
    int z = x * (x >= y) + y * (y > x);
    printf("The max numebr is %d \n", z);
}
