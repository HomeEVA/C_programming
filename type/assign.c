#include <stdio.h> 
#include <math.h>
int main(int argc, char const *argv[])
{
    int i; 
    char c; 
    
    i = 5;
    i = c;
    c = i; 

    sqrt((double) i);
    double sqrt(double);

    double root2 = sqrt(2);
   

}

void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

void strcats(char s[], char t[]) 
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    while((s[i++] = t[i++]) != '\0')
    {
        ;
    }
}