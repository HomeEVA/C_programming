#include <stdio.h>

int wordslength[12]; /* used to store length of each word in the input */

int main(int argc, char const *argv[])
{
    
    
    int c; 
    int lw; // length of word 
    int wn; // word number


    lw = wn = 0; 

    while ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == ' ' || c == '\t') 
        {
            /* TODO: 
            1. store length of current word into the array wordslength[]
            2. reset the length of word (lw) */
            wordslength[wn] = lw; 
            lw = 0;
            ++wn; // increase word number when word ends
            
        } 
        else 
        {
            /* TODO: increase lw by 1 */
            ++lw;
        }
        /* TODO: increase the index of the array pointer (wn) */
        
    }

    for (int i = 0; i <= 11; ++i)
    {
        /*
        int len = wordslength[i];
        while (len > 0)
        {
           
            putchar('#');
            --len;
        }
        */

        for (int j = 0; j < wordslength[i]; j++)
        {
            /* code */
            putchar('#');
        }
        
       
        if (wordslength[i] > 0) 
        {
            /* TODO: switch line */
            putchar('\n');
        } 
        
        
        
       
        
    }


}