#include <stdio.h>

int outputbigger1(int, int);
int outputbigger2(int, int);

int main(int argc, char const *argv[])
{
    printf("%d %d", outputbigger1(3,4), outputbigger2(3,4));


}

int outputbigger1(int a, int b) 
{
    int z; 

    if (a > b)
    {
        z = a; 
    }
    else 
    {
        z = b;
    }
    return z;
}

int outputbigger2(int a, int b)
{
    int z;

    z = (a > b) ? a : b; /* z = max(a, b) */

    return z;
}