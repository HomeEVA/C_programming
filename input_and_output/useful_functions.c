#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

int main (int argc, char const *argv[]) 
{
    system("date");
    char *s = "Oh my god, god save me!";
    int c = 'g';

    char *p = strrchr(s,c); 

    if (p != NULL) {
        printf("the last time g appears is %d\n", (int)(p - s));
    } else {
        printf("character not found");
    }
    
    char *m = strchr(s,c);

    if (m != NULL) {
        printf("the first time g appears is at %d", (int)(m - s));
    } else {
        printf("character not found");
    }

}