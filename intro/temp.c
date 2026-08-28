#include <stdio.h>

/* when fahr= 0, 20, ..., 300, print temperature */
int main(int argc, char const *argv[]) 
{
    float fahr, celsius;
    int lower, upper, step; 

    lower = 0; 
    upper = 300; 
    step = 30; 

    printf("-- celcius to fahr --\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius * 9.0) / 5.0 + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}