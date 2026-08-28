#include <stdio.h>


int main(int argc, char const *argv[]) 
{
    int x = 1, y = 2, z[10];
    int *ip;     /* ip is pointer point to type int */
    int *iq;

    ip = &x;    /* ip now points to x */
    y = *ip;    /* the value of y is now 1 */
    *ip = 0;    /* the value of x is now 0 */
    ip = &z[0]; /* ip now points to z[0] */

    ip = &y;
    *ip = *ip + 10;
    *ip += 1;
    ++*ip;
    (*ip)++; /* must add the bracket */

    iq = ip;
    printf("%d\n", *ip);
    printf("%d", *iq);
}