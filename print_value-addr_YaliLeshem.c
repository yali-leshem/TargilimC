/*------------------------------------------------------
* Filename: print_value-addr_YaliLeshem.c
* Description: program that prints for each element in array it's value and address using pointers
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

#define LEN 8

/*------------------------------------------------------
* Function Name - value_address
*
* Function Purpose - Go through all elements in both arrays and print their value using pointers, and their address in hexadecimal
*
* Parameters – char array chars, has 8 characters and array of 8 integers
*
-------------------------------------------------------*/

void value_address (char chars[], int ints[]) {
    int index;
    char *p1 = chars;
    int *p2 = ints;

    for (index = 0; index < LEN; index++) {
        printf("The %d-th char is: %c \n", index+1, *(p1+index)); // access value using pointer
        printf("The address is: 0x%x \n", (p1+index));
        printf("\n");

        printf("The %d-th integer is: %d \n", index+1, ints[index]); // access value using index
        printf("The address is: 0x%x \n", (p2+index));
        printf("\n");
    }
}

int main() {
    char chars[LEN];
    int index, ints[LEN];

    // Recieve the 8 characters to array
    printf("Enter %d characters: \n", LEN);
    for (index = 0; index < LEN; index++)
        scanf(" %c", &chars[index]);

    // Recieve the 8 integers to array
    printf("Enter %d integers: \n", LEN);
    for (index = 0; index < LEN; index++)
        scanf(" %d", &ints[index]);

    value_address(chars, ints);
    return 0;
}