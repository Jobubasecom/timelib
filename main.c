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
  struct date thisDate;

  // declare variables necessary for calculation
  int current_day = 0;

  // use input_date
  thisDate = input_date();

  current_day = day_of_the_year(thisDate);

  // tell user what day it is
  printf("Today is day %i of this year\n", current_day);
  return 0;
}
