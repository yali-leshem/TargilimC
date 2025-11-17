/*------------------------------------------------------
* Filename: calcAge.c
* Description: Finding your current age based on birth and current dates.
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

int main() {
    int curr_year, curr_month, curr_day;
    int birth_year, birth_month, birth_day;

    printf("Enter current date: \n");
    scanf("%d/%d/%d", &curr_day, &curr_month, &curr_year);

    printf("Enter birth date: \n");
    scanf("%d/%d/%d", &birth_day, &birth_month, &birth_year);

    // Total difference in days
    int total_days = (curr_year - birth_year) * 365
                   + (curr_month - birth_month) * 30
                   + (curr_day - birth_day);

    float age_months = total_days / 30.0f;
    float age_years  = total_days / 365.0f; // to have fraction of the years and months of their age

    printf("Age in days: %d\n", total_days);
    printf("Age in months: %.5f\n", age_months);
    printf("Age in years: %.5f\n", age_years);

    return 0;
}