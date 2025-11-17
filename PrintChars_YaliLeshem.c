/*------------------------------------------------------
* Filename: PrintChars_YaliLeshem.c
* Description: Print a square full of characters by a given size
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

char find_char_by_conditions(int square_len) {
    if (square_len%2 == 0)
        return '*';
    else if (square_len%3 == 0)
        return '^';
    else if (square_len%5 == 0)
        return '%';
    else
        return '@';
}

int main () {

    char special_char;
    int square_len, i, j;
    printf("Enter your desired length for the square: \n");
    scanf("%d", &square_len);

    if (square_len <= 0) {
        printf("Bad Input! \n");
        return 1; // stop program execution due to bad input
    }

    special_char = find_char_by_conditions(square_len);

    for (i = 0; i < square_len; i++) {
        for (j = 0; j < square_len; j++)
            printf("%c", special_char);
        printf("\n");
    }

    return 0;
}
