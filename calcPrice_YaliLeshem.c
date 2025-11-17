/*------------------------------------------------------
* Filename: calcPrice.c
* Description: Find area, weight and price of package by given data of how it's calculated.
* Author: Yali Leshem
-------------------------------------------------------*/
#include <stdio.h>

int main () {
    int width_mm, length_mm, weight_gr;

    printf("Enter package's width in mm: \n");
    scanf("%d", &width_mm);

    printf("Enter package's length in mm: \n");
    scanf("%d", &length_mm);

    printf("Enter package's weight in grams: \n");
    scanf("%d", &weight_gr);

    double area_squared_cm = (width_mm*length_mm)/100;
    double weight_kg = weight_gr/1000;

    printf("Total area of the package in cms is: %.2f \n", area_squared_cm); // storing exactly 2 digits after decimal point

    printf("Total weight of the package in Kgs is: %.3f \n", weight_kg); // storing exactly 3 digits after decimal point

    printf("Total price of the package is: %.2f \n", 5.5 + 11*((int) weight_kg) + 0.03*((int) area_squared_cm) + 0.01*(area_squared_cm/weight_kg));

    return 0;

}
