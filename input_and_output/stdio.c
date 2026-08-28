#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lower(void); 
void higher(void); 
int main(int argc, char const *argv[])
{
    if (strcmp(argv[0], "./tolower") == 0) {
        lower();
    } else if (strcmp(argv[0], "./tohigher") == 0) {
        higher();
    }
    return 0;
}

void lower(void) 
{
    int c; 

    while ((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
}

void higher(void) 
{
    int c; 

    while ((c = getchar()) != EOF) {
        putchar(toupper(c));
    }
}