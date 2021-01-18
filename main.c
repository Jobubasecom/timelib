/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
 *
 **/
int day_of_the_year(int day, int month, int year)
{
    return 0;
}

int main()
{
  // declare variables "year", "month", "day" and "leap"
  int year, month, day, leap = 0;

  // declare variables necessary for calculation
  int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int leap_days_per_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int current_day = 0;

  // prompt user for input and save in year variable
  do {
    printf("Current year: ");
    scanf("%i", &year);
  } while(year < 1);

  // calculate leap year
  // is "year" dividable by 4?
  if (year % 4 == 0) {
    // is "year" dividable by 100?
    if (year % 100 == 0) {
      // is "year" dividable by 400?
      if (year % 400 == 0) {
        // set leap to 1 (true)
        leap = 1;
      }
    }
    // set leap to 1 (true)
    else {
      leap = 1;
    }
  }

  // differentiate for leap years
  if (leap) {
    // prompt user for month and day
    do {
      printf("Current month: ");
      scanf("%i", &month);
    } while(month < 1 || month > 12);

    do {
      printf("Current day: ");
      scanf("%i", &day);
    } while(day < 1 || day > leap_days_per_month[month-1]);

    // for each month add the corresponding days to the total
    for (int i = 0; i < month-1; i++) {
      current_day += leap_days_per_month[i];
    }
    // add days entered by user to total
    current_day += day;
  } else {
    // prompt user for month and day
    do {
      printf("Current month: ");
      scanf("%i", &month);
    } while(month < 1 || month > 12);

    do {
      printf("Current day: ");
      scanf("%i", &day);
    } while(day < 1 || day > days_per_month[month-1]);

    // for each month add the corresponding days to the total
    for (int i = 0; i < month-1; i++) {
      current_day += days_per_month[i];
    }
    // add days entered by user to total
    current_day += day;
  }

  // tell user what day it is
  printf("Today is day %i of this year\n", current_day);
  return 0;
}
