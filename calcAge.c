/*------------------------------------------------------
* Filename: calcAge.c
* Description: Finding your current age based on birth and current dates.
* Author: Yali Leshem
-------------------------------------------------------*/

#include <stdio.h>

int main () {
    int curr_year, curr_month, curr_day, birth_year, birth_month, birth_day, diff_years, diff_months, diff_days;
    printf("Enter current date: \n");
    scanf("%d/%d/%d", &curr_day, &curr_month, &curr_year);

    printf("Enter birth date: \n");
    scanf("%d/%d/%d", &birth_day, &birth_month, &birth_year);

    diff_years = curr_year - birth_year;
    if (curr_month < birth_month || (curr_month == birth_month && curr_day < birth_day))
        diff_years--;  // subtract 1 if birthday hasn’t occurred yet this year

    diff_months = (curr_month - birth_month + 12) % 12; // months will always be 0–11
    diff_days = curr_day - birth_day;
    if (diff_days < 0) {
        diff_days += 30;  // borrow 30 days from previous month
        diff_months = (diff_months - 1 + 12) % 12;        
    }


    printf("Age in years: %d \n", diff_years);
    printf("Age in months: %d \n", diff_months);
    printf("Age in days: %d \n", diff_days);

    return 0;
}