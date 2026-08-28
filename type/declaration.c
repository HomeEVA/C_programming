#include <stdio.h>

// All variables needs to be declared before use 
#define MAXLINE 1000
int lower, upper, step; 
char c, s[100]; 

char esc = '\\';
int i = 0;
int limit = MAXLINE + 1;
float eps = 1.0e-5;

const double e = 2.718; 
const char msg[] = "warning: ";



int main (int argc, char const *argv[])
{
    int year; 
    int lim = 5;

    year = 1995;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        printf("%d is a leap year\n", year);
    }
    else
    {
        printf("%d is not a leap year\n", year);
    }
    
    /* method 1 */
    for (int i=0; i < lim-1; ++i)
    {
        if ((c = getchar()) == '\n')
        {
            break; 
        }
        if (c == EOF)
        {
            break;
        }
        s[i] = c; 

    }

    /* method 2*/
    enum loop {NO, YES};
    enum loop okloop = YES; 

    i = 0; 
    while (okloop == YES)
    {
        if (i >= lim - 1)
        {
            okloop = NO;
        }
        else if ((c = getchar()) == '\n')
        {
            okloop = NO;
        }
        else if (c == EOF)
        {
            okloop = NO;
        }
        else
        {
            s[i] = c;
            ++i;
        }
    }
}



