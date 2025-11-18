/*------------------------------------------------------
* Filename: str_to_int_a_YaliLeshem.c
* Description: convert a string to integer and add 36 using atoi
* Author: Yali Leshem
-------------------------------------------------------*/

#include <Stdio.h>
#include <stdlib.h>
 
#define MAX_LEN 10 // assuming the string could be represented as type int, meaning no more than 10 digits (signed integer, including negatives)
#define CONST_ADD 36

int main() {
    int converted;
    char str[MAX_LEN+1]; // added 1 for null terminator
    scanf("%10s", str);

    converted = atoi(str);

    if (converted != 0) {
        converted += CONST_ADD;
    } else { // atoi returns 0 if the string is not a number
        printf("not a number \n");
        return 1;
    }

    printf("The number is: %d \n", converted);

    return 0;
}