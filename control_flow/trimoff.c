#include <stdio.h>
#include <string.h>

int trim(char s[]);

int main(int argc, char const *argv[])
{
    char s[5];
    s[0] = 's';
    s[1] = ' ';
    s[2] = 'd';
    s[3] = '\t';
    s[4] = '\0';

    printf("%d\n", trim(s));
    printf("%d", 2);
}

int trim(char s[])
{
    int n; 

    for (n = strlen(s)-1; n >= 0; n--)
    {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
        {
            break;
        }
    }
    s[n + 1] = '\0';

    return n; // print the first index that is not a space, indent and nextline
}
