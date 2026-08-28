#include <stdio.h> 

int bitcount(unsigned x);
int bitcountimprove(unsigned x);

int main(int argc, char const *argv[])
{
    int m = bitcount(217);
    int t = bitcount(217);
    printf("%d %d", m, t);
}

int bitcount(unsigned x) 
{
    int b; 
    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
        {
            b++;
        }
    }

    return b; 
}

int bitcountimprove(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x-1) )
    {
        b++;
    }

    return b;
}