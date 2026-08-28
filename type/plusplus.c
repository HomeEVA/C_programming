#include <stdio.h>

int main (int argc, char const *argv[])
{
    int m, t, n;

    n = 6; 
    /* first do n = n + 1 then assign n to m */
    m = ++n;
    
    printf("%d\n", m);
    
    int l = 6;

    /* assign l to t first and then do l = l + 1 */
    t = l++;

    printf("%d", t);
}