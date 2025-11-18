/*------------------------------------------------------
* Filename: const_pointer_YaliLeshem.c
* Description: update a pointer to a constant integer using a constant integer pointer
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

#define ARUTZ_NUM 5

int main () {
    int arutz_gili;
    const int arutz = ARUTZ_NUM;
    const int *p1 = &arutz;
    printf("Number of arutz is: %d \n", *p1);

    printf("Gili, enter your arutz number: \n");
    scanf(" %d", &arutz_gili); // user enters new arutz number

    int* const p2 = &arutz_gili;
    p1 = p2; // by arithmetic pointers, will use the pointer to constant number to update p1

    printf("Number of arutz now is: %d \n", *p1);

    return 0;
}