#include <ctype.h>
#include <stdio.h>

int atoi(char s[]);

int main(int argc, char const *argv[])
{
    char s[4]; 
    s[0] = '+';
    s[1] = '4';
    s[2] = '3';
    s[3] = '0';

    int m = 560 - atoi(s);

    printf("%d", m);

}

/* turn char s into int */
int atoi(char s[])
{
    int i, n, sign;

    for(i = 0; isspace(s[i]); i++)
    {
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (n = 0; isdigit(s[i]); i++)
    {
        n = 10 * n + (s[i] - '0');
    }
    return sign * n;
}