/*------------------------------------------------------
* Filename: coke_and_roll_YaliLeshem_YonatanShami.c
* Description: Drinks machine functionality for agents with secured way to send messages
* Author: Yali Leshem and Yonatan Shami
-------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

#define PRICE_COLA 5.20
#define PRICE_DIET 7.20
#define PRICE_ORANGEADE 3.40
#define PRICE_SCHWEPPS 4.5
#define PRICE_GRAPE_JUICE 3.5
#define PRICE_MIN_WATER 2.5
#define EXIT_VAL -1
#define INVALID_VAL 0
#define COINS_LEN 6
#define CONST_DIV_OVERFLOW 0.01

// Function recieves a character and returns price of drink user wants, or finds invalid/'E'.
double price_for_drink (char input) {
    switch (input) {
        case 'C':
            return PRICE_COLA;
        case 'D':
            return PRICE_DIET;
        case 'O':
            return PRICE_ORANGEADE;
        case 'S':
            return PRICE_SCHWEPPS;
        case 'G':
            return PRICE_GRAPE_JUICE;
        case 'W':
            return PRICE_MIN_WATER;
        case 'E':
            return EXIT_VAL;
        default:
            return INVALID_VAL;
    }
}

int main() {
    char input;
    double price, change, sum = 0, coins[] = {0.1, 0.5, 1.0, 2.0, 5.0, 10.0};
    int i, coins_count, is_agent = 0, coins_agent[] = {1, 0, 1, 3, 3, 7};

    while (1) {
            printf(" *************** Welcome to the drinks machine *************** \n");
            printf("Please select the drink you would like to order: \n");
            printf("press 'C' for Coca-Cola \n");
            printf("press 'D' for Diet-Cola \n");
            printf("press 'O' for Orangeade \n");
            printf("press 'S' for Schweppes \n");
            printf("press 'G' for Grape juice \n");
            printf("press 'W' for Mineral water \n");

            scanf(" %c", &input);
            price = price_for_drink(toupper(input)); // Calcualte price for drink, or find if invalid or turning machine off
            
            if (price == INVALID_VAL) {
                printf("No such drink, try again! \n");
                continue; // In case input's invalid, continue to next iteration
            }

            if (price == EXIT_VAL) { // In case 'E' recieved as input, turn off drinks machine
                printf("Drinks machine is turned off \n");
                break;
            }

            printf("The price of the drink is %.2fNIS \n", price);

            for (i = 0; i < COINS_LEN; i++) {
                printf("Enter amount of %.2f NIS: ", coins[i]);
                scanf("%d", &coins_count);
                
                if (coins_count != coins_agent[i])
                    is_agent = 1; // In case coins insrted doesn't match agent's

                sum += coins_count * coins[i]; // sum all coins insrted to machine
                printf("\n");
            }

            printf("The machine received payment of %.2f NIS \n", sum);

            if (is_agent == 0) // In case agent recieving message from drinks machine
                printf("Special agent, please respond!!! \n");

            printf("Payment received. \n");

            change = sum-price;

            for (i = COINS_LEN-1; i > -1; i--) { // Spare change per each coin
                printf("Machine returned %d coins of %.2f NIS \n", ((int)(change/coins[i] + CONST_DIV_OVERFLOW)), coins[i]);

                change -= (((int)(change/coins[i])) * coins[i]); // Update change by sparing the coins iteratively
            }

            printf("Enjoy your drink!! \n");

    }

    return 0;
}