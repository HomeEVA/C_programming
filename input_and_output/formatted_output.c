#include <stdio.h>

int main(int argc, char const *argv[])
{
    int max = 3; 
    char s[] = "Sting";

    printf("%.*s", max, s);

    int max2 = 5;
    char t[] = "yes";
    printf("%.*s\n", max2, t);

    char mystring[] = "Harry Potterrr!";
    char hisstring[] = "Hello, world";
    printf("%s\n", mystring);
    printf("%13s\n", mystring);
    printf("%.13s\n", mystring);
    printf("%20.13s\n", mystring);
    printf("%-20.13s\n", mystring);
}