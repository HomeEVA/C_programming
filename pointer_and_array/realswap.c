#include <stdio.h>

void swap(int *px, int *py);

int main(int argc, char const *argv[])
{
    int a = 2;
    int b = 3;
    swap(&a, &b);
    printf("a = %d, b = %d", a, b);

}

void swap(int *px, int *py)
{
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}