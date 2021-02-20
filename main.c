/**
* Calculate the day of the year
* Author: Johannes Busch
* Date: 20.2.2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include "timelib.h"


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
