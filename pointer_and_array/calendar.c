#include <stdio.h> 
void month_day(int year, int yearday, int *pmonth, int *pday);
int main(int argc, char const *argv[]) 
{
    int m, d;
    month_day(1988, 93, &m, &d);
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* convert from month day version into day of year */
int day_of_year(int year, int month, int day) 
{

    int i, leap; 
    if (year <= 0 || month <= 0 || day <= 0 || month > 12 || day > daytab[leap][month]) {
        return -1;
    }

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0; 
    for (i = 0; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}

/* convert from day of year version to month day version */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    if (year <= 0) {
        *pmonth = -1; 
        *pday = -1; 
    }
    
    if (leap == 0) {
        if (yearday > 365) {
            *pmonth = -1; 
            *pday = -1; 
        }
    } 

    if (leap == 1) {
        if (yearday > 366) {
            *pmonth = -1; 
            *pday = -1; 
        }
    }
    for (i = 1; yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
        printf("yearday: %d, i = %d\n", yearday, i);
    }

    *pmonth = i; 
    *pday = yearday;

    printf("month: %d, day: %d", *pmonth, *pday);
}
