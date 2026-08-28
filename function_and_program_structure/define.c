#include <stdio.h> 

#define square(x) x * x 
#define dprint(expr) printf(#expr " = %g\n", expr)
#define paste(front, back) front ## back

#define swap(t, x, y)  {t z = x; x = y; y = z;}

int main(int argc, char const *argv[])
{
    //int x = 2;

    //printf("%d", square(x+1));

    //dprint(1.0/2.0);
    int x = 2; 
    int y = 3;
    int xy;
    //swap(int, x, y); 
    //printf("%d %d", x, y);
    paste(x, y);
    printf("%d", xy);
}








