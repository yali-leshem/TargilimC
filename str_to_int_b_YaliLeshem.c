/*------------------------------------------------------
* Filename: str_to_int_b_YaliLeshem.c
* Description: convert a string to integer and add 36 using non-atoi conversion
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 10
#define CONST_ADD 36

int main() {
    char str[MAX_LEN+1];
    int num = 0;

    scanf("%10s", str);  // Ensure only 10 characters are for input (cut in case)

    // check input for validity and that they're all digits
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            printf("Not a number \n");
            return 1;
        }
    }

    // convert the string to integer digit by digit (by calculating units 10^d)
    for (int i = 0; str[i] != '\0'; i++) {
        num = num * 10 + (str[i] - '0');
    }

    num += CONST_ADD; // add const of 36 as requested

    printf("The number is: %d \n", num);

    return 0;
}