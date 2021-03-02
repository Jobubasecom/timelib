#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

// struct for dates
struct date {
    int day;
    int month;
    int year;
};

// prototypes for functions
int is_leapyear(int year);
int day_of_the_year(struct date thisDate);
int get_days_for_month(struct date thisDate);
int exists_date(struct date thisDate);
struct date input_date();


#endif // TIMELIB_H_INCLUDED
