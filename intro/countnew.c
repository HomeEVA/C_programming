#include <stdio.h>

int main(int argc, char const *argv[]) 
{
    int c, nl;

    nl = getchar();
    while ((c = getchar()) != EOF)
    {
        if (c != ' ') 
        {
            putchar(c); 
        } 
        
        if (c == ' ')
        {
            if (nl != ' ')
            {
                putchar(c);
            }
        }

        nl = c; 

        
    }
    
}
 