#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;

    c = getchar(); 
    while (c != EOF) 
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        if (c == '\b')
        {
            printf("\\b");

        }
        if (c == '\\')
        {
            printf("\\\\");
        }
        if (c != '\t' && c != '\b' && c !='\\')
        {
            putchar(c);
        }
        c = getchar();
    }
}