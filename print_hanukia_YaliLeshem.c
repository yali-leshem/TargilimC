/*------------------------------------------------------
* Filename: print_hanukia_YaliLeshem.c
* Description: Print hanukia and the number of candles by the given input
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

#define CANDLE "  ##  "
#define PRINT0 0
#define PRINT1 printf(CANDLE)
#define PRINT2 PRINT1, PRINT1
#define PRINT3 PRINT2, PRINT1
#define PRINT4 PRINT3, PRINT1
#define PRINT5 PRINT4, PRINT1
#define PRINT6 PRINT5, PRINT1
#define PRINT7 PRINT6, PRINT1
#define PRINT8 PRINT7, PRINT1

#define REST_OF_HANUKIA \
    printf(" ####  ####  ####  ####  ####  ####  ####  #### \n"); \
    printf(" ####  ####  ####  ####  ####  ####  ####  #### \n"); \
    printf(" ####  ####  ####  ####  ####  ####  ####  #### \n"); \
    printf("                       ||\n"); \
    printf("                       ||\n"); \
    printf(" ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n");

int main() {
    int day;
    printf("Enter the day number of hanukah \n");
    scanf("%d", &day);

    day == 0 && (PRINT0, 1);
    day == 1 && (PRINT1, 1);
    day == 2 && (PRINT2, 1);
    day == 3 && (PRINT3, 1);
    day == 4 && (PRINT4, 1);
    day == 5 && (PRINT5, 1);
    day == 6 && (PRINT6, 1);
    day == 7 && (PRINT7, 1);
    day == 8 && (PRINT8, 1);

    printf("\n");

    REST_OF_HANUKIA
    
    return 0;
}
