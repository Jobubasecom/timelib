/**
* Calculate the day of the year
* Author: Johannes Busch
* Date: 25.1.2021
 **/

#include <stdio.h>
#include <stdlib.h>

// prototypes
int is_leapyear(int year);
int day_of_the_year(int day, int month, int year);

int main()
{
  // declare variables "year", "month", "day" and "leap"
  int year, month, day, leap = 0;
  int days_in_february = 28;

  // declare variables necessary for calculation
  int current_day = 0;

  // prompt user for input and save in year variable
  do {
    printf("Current year: ");
    scanf("%i", &year);
  } while(year < 1);

  if (leapyear(year)) {
    days_in_february = 29;
  }
  int days_per_month[12] = {31, days_in_february, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // prompt user for month and day
  do {
    printf("Current month: ");
    scanf("%i", &month);
  } while(month < 1 || month > 12);

  do {
    printf("Current day: ");
    scanf("%i", &day);
  } while(day < 1 || day > days_per_month[month-1]);

  current_day = day_of_the_year(day, month, year);

  // tell user what day it is
  printf("Today is day %i of this year\n", current_day);
  return 0;
}

int is_leapyear(int year) {
  if (year < 1582 || year > 2400) {
    return -1;
  }

  // is "year" dividable by 4?
  if (year % 4 == 0) {
    // is "year" dividable by 100?
    if (year % 100 == 0) {
      // is "year" dividable by 400?
      if (year % 400 == 0) {
        // return 1 (true)
        return 1;
      }
    }
    // return 1 (true)
    else {
      return 1;
    }
  }

  //otherwise return 0 (false)
  return 0;
}

int day_of_the_year(int day, int month, int year) {
  int days_in_february = 28;
  // use leapyear function
  if (leapyear(year)) {
    days_in_february = 29;
  }

  int days_per_month[12] = {31, days_in_february, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // for each month add the corresponding days to the total
  int current_day = 0;
  for (int i = 0; i < month-1; i++) {
    current_day += days_per_month[i];
  }
  // add days entered by user to total
  current_day += day;

  return current_day;
}
