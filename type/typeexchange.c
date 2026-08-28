#include <stdio.h>

int atoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    {
        n = 10 * n + (s[i] - '0');
    }
    
    return n;
}

/* lower : uncapitalise */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 'a' -'A';
    }
    else 
    {
        return c; 
    }
}

int newlower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}