/*------------------------------------------------------
* Filename: calcPrice_YaliLeshem.c
* Description: Find area, weight and price of package by given data of how it's calculated.
* Author: Yali Leshem
-------------------------------------------------------*/
#include <stdio.h>

#define GR_PER_KG (1000)
#define SQUARED_CM (100)
#define PRICE_PER_PACK (5.5)
#define PRICE_PER_KG (11)
#define CENTS_PER_SQCM (0.03)
#define SINGLE_CENT (0.01)

int main () {
    int width_mm, length_mm, weight_gr;

    printf("Enter package's width in mm: \n");
    scanf("%d", &width_mm);

    printf("Enter package's length in mm: \n");
    scanf("%d", &length_mm);

    printf("Enter package's weight in grams: \n");
    scanf("%d", &weight_gr);

    double area_squared_cm = (width_mm*length_mm)/SQUARED_CM;
    double weight_kg = weight_gr/GR_PER_KG;
    double total_price = PRICE_PER_PACK + PRICE_PER_KG*((int) weight_kg) + CENTS_PER_SQCM*((int) area_squared_cm) + SINGLE_CENT*(area_squared_cm/weight_kg);
    
    printf("Total area of the package in cms is: %.2f \n", area_squared_cm); // storing exactly 2 digits after decimal point

    printf("Total weight of the package in Kgs is: %.3f \n", weight_kg); // storing exactly 3 digits after decimal point

    printf("Total price of the package is: %.2f \n", total_price);

    return 0;

}
