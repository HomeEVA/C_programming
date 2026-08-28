#include <stdio.h>
#define MAXLINE 1000    /* maximum allowed length */

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

int main (int argc, char const *argv[]) 
{
    int len;    /* length of current line */
    int max;    /* current maximum length */
    char line[MAXLINE]; /* current line */
    char longest[MAXLINE];  /* used to store longest line */

    max = 0;
    len = getlines(line, MAXLINE);
    while(len > 0)
    {
        if (len > max) {
            max = len;
            copy(longest, line); 
        }
        len = getlines(line, MAXLINE);
    }
    if (max > 0)    /* if such line exists */
    {
        printf("%s", longest);
    }
    return 0;

}

/* getline function: read a line into s and return its length */
int getlines(char s[], int lim)
{
    int c, i;
    
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n') 
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy method: copy from into to; assume that to is big enough */
void copy(char to[], char from[])
{
    int i;
    
    i = 0;
    while((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}