#include <stdio.h>

void swap(int x, int y);

int main(int argc, char const *argv[]) 
{
    int a; 
    int b; 
    a = 2;
    b = 3;

    swap(a, b); 

    printf("a = %d, b = %d", a, b);
}
void swap(int x, int y) /* very wrong */
{
    int temp; 

    temp = x; 
    x = y; 
    y = temp;
    printf("x = %d, y = %d\n",x, y);
}

