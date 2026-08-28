#include <stdio.h>
int strlens(char *s);

int strlens1(char *s);

int main(int argc, char const *argv[])
{
    printf("%d\n", strlens("hello, world"));
}

/* strlen: return length of char array s */
int strlens(char *s)
{
    int n; 

    for (n = 0; *s != '\0'; s++) {
        n++;
    }

    return n;
}

int strlens1(char *s)
{
    char *p = s;

    while (*p != '\0') {
        p++;
    }

    return p - s;
}