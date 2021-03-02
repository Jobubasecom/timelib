/**
* functions to calculate the day of the year
* Author: Johannes Busch
* Date: 20.2.2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"


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
int day_of_the_year(struct date thisDate)
{
  // for each month add the corresponding days to the total
  int current_day = 0;
  for (int i = 0; i < thisDate.month; i++) {
    current_day += get_days_for_month(thisDate);
  }
  // add days entered by user to total
  current_day += thisDate.day;

  // return the result
  return current_day;
}

// return the day of any asked month (leap years included)
int get_days_for_month(struct date thisDate)
{
  // array for info about months, added month 0 with 0 days for easy indexing
  int days_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // change days of 2nd month for leap years
  if (is_leapyear(thisDate.year)) {
    days_per_month[2] = 29;
  }

  // return resulting amount of days
  return days_per_month[thisDate.month];
}

// validate given date, return 0 on invalid dates
int exists_date(struct date thisDate)
{
  // validate year
  if (thisDate.year < 1582 || thisDate.year > 2400) {
    return 0;
  }

  // validate month
  if (thisDate.month < 1 || thisDate.month > 12) {
    return 0;
  }

  // validate day (including leap years)
  if (thisDate.day < 1 || thisDate.day > get_days_for_month(thisDate)) {
    return 0;
  }

  // if the date is valid, return 1
  return 1;
}

struct date input_date(void)
{
    struct date newDate;
  // prompt user for input and save to the variables that are pointed to
  do {
    // prompt user for year, month and day
    printf("Current year: ");
    scanf("%i", &newDate.year);

    printf("Current month: ");
    scanf("%i", &newDate.month);

    printf("Current day: ");
    scanf("%i", &newDate.day);
  } while(!exists_date(newDate));

  return newDate;
}
