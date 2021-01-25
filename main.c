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
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);

int main()
{
  // declare variables "year", "month", "day" and "leap"
  int year = 0, month = 0, day = 0;

  // declare variables necessary for calculation
  int current_day = 0;

  // prompt user for input and save in year variable
  do {
    printf("Current year: ");
    scanf("%i", &year);

  // prompt user for month and day
    printf("Current month: ");
    scanf("%i", &month);

    printf("Current day: ");
    scanf("%i", &day);
  } while(!exists_date(day, month, year));

  current_day = day_of_the_year(day, month, year);

  // tell user what day it is
  printf("Today is day %i of this year\n", current_day);
  return 0;
}

int is_leapyear(int year)
{
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

int day_of_the_year(int day, int month, int year)
{
  int days_in_february = 28;
  // use leapyear function
  if (is_leapyear(year)) {
    days_in_february = 29;
  }

  // for each month add the corresponding days to the total
  int current_day = 0;
  for (int i = 0; i < month; i++) {
    current_day += get_days_for_month(i, year);
  }
  // add days entered by user to total
  current_day += day;

  return current_day;
}

int get_days_for_month(int month, int year)
{
  int days_in_february = 28;

  if (is_leapyear(year)) {
    days_in_february = 29;
  }

  int days_per_month[13] = {0, 31, days_in_february, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  return days_per_month[month];
}

int exists_date(int day, int month, int year)
{
  if (year < 1582 || year > 2400) {
    return 0;
  }

  if (month < 1 || month > 12) {
    return 0;
  }

  if (day < 1 || day > get_days_for_month(month, year)) {
    return 0;
  }

  return 1;
}
