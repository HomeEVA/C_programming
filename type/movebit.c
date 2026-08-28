#include <stdio.h> 

unsigned testflip(int n);
int testand(int n);
int testor(int n);

int main(int argc, char const *argv[])
{
    int n; 
    n = 7; 

    //int m = 255;
    
    //n = n & m;

    //n = n & 0177;

    //int SET_ON = 248;
    //n = n | SET_ON;

    //n = ~n;

    int m = testor(n);

    int p = testand(n);

    int o = testflip(n);

    printf("%d %d %d", m, p, o);


}

/* use case: change a certain number of digits to 1 */
int testor(int n)
{
    int SET_ON = 248; // the fourth to eighth digits set to 1

    return n | SET_ON;

}

/* use case: keep a set of digits in the number */
int testand(int n)
{
    int MASK = 6; // only keep the last 7 digits of the number, set rest to 0

    return n & MASK;


}

unsigned testflip(int n)
{
    return ~n;
}