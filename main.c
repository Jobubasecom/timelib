/**
* Calculate the day of the year
* Author: Johannes Busch
* Date: 25.1.2021
 **/

#include <stdio.h>
#include <stdlib.h>

// prototypes for functions
int is_leapyear(int year);
int day_of_the_year(int day, int month, int year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int input_date(int *day, int *month, int *year);

int main()
{
  // declare variables "year", "month", "day" and "leap"
  int year = 0, month = 0, day = 0;

  // declare variables necessary for calculation
  int current_day = 0;

  // use input_date
  input_date(&day, &month, &year);

  current_day = day_of_the_year(day, month, year);

  // tell user what day it is
  printf("Today is day %i of this year\n", current_day);
  return 0;
}

// returns 1 if the year is a leap year, otherwise return 0
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

// calculate what day of the year it is
int day_of_the_year(int day, int month, int year)
{
  // for each month add the corresponding days to the total
  int current_day = 0;
  for (int i = 0; i < month; i++) {
    current_day += get_days_for_month(i, year);
  }
  // add days entered by user to total
  current_day += day;

  // return the result
  return current_day;
}

// return the day of any asked month (leap years included)
int get_days_for_month(int month, int year)
{
  // array for info about months, added month 0 with 0 days for easy indexing
  int days_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // change days of 2nd month for leap years
  if (is_leapyear(year)) {
    days_per_month[2] = 29;
  }

  // return resulting amount of days
  return days_per_month[month];
}

// validate given date, return 0 on invalid dates
int exists_date(int day, int month, int year)
{
  // validate year
  if (year < 1582 || year > 2400) {
    return 0;
  }

  // validate month
  if (month < 1 || month > 12) {
    return 0;
  }

  // validate day (including leap years)
  if (day < 1 || day > get_days_for_month(month, year)) {
    return 0;
  }

  // if the date is valid, return 1
  return 1;
}

int input_date(int *day, int *month, int *year)
{
  // prompt user for input and save to the variables that are pointed to
  do {
    // prompt user for year, month and day
    printf("Current year: ");
    scanf("%i", year);

    printf("Current month: ");
    scanf("%i", month);

    printf("Current day: ");
    scanf("%i", day);
  } while(!exists_date(*day, *month, *year));

  return 1;
}
