#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;

    int a[30];

    for (int j = 0; j < 30; j++) 
    {
        a[j] = j;
    }

    n = 30;

    for (int i = 0; i < n; i++) 
    {
        printf("%6d%c", a[i], (i%10 == 9 || i == n-1) ? '\n' : ' ');
    }
}