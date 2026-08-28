#include <stdio.h>

#define IN 1
#define OUT 0 

int main(int argc, char const *argv[])
{
    int c, state;
    state = 1;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        if (state == OUT)
        {
            printf("\n");
            state = IN; 
        }
        else 
        {
            putchar(c);
        }


    }
}