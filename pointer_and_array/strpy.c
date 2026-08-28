#include <stdio.h>
#include <stdlib.h>
/* copy the string pointer t points to to the address where pointer 
s points to */
void strcpy1(char *s, char *t);
void strcpy2(char *s, char *t);
void strcpy3(char *s, char *t); 
void strcpy4(char *s, char *t); 


int main(int argc, char const *argv[])
{
    char *t = "YES"; 
    char *s = malloc(4);

    if (s != NULL) {
        strcpy1(s, t);
        printf("%s", s);
        free(s);
        s = NULL;
    } 
    return 0;
    
}
void strcpy1(char *s, char *t) 
{
    int i; 
    
    i = 0;
    while(((s[i] = t[i]) != '\0')) {
        i++;
    }
}

void strcpy2(char *s, char *t) 
{
    int i; 
    i = 0;
    while((*s = *t != '\0')) {
        s++;
        t++;
    }
}

void strcpy3(char *s, char *t)
{
    int i = 0;
    while((*s++ = *t++) != '\0') {
        ;
    }
}

void strcpy4(char *s, char *t) 
{
    int i = 0;
    while (*s++ = *t++) {
        ;
    }
}