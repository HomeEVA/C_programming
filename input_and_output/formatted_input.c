#include <stdio.h>

int main(int argc, char const *argv[])
{
    double sum, v; 

    sum = 0;
    while(scanf("%lf", &v) == 1) {
        printf("\t%.3f\n", sum += v); 
    }
    return 0;
}