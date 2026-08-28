#include <stdio.h> 

int main(int argc, char const *argv[])
{
    int a[10];

    int *pa;

    pa = &a[0];

    pa = a;

    int x = *pa; /* copy the value in a[0] into the variable x*/
}