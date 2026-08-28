#include <stdio.h>

int binsearch(int x, int v[], int n);
int binsearchnew(int x, int v[], int n);

int main(int argc, char const *argv[])
{
    int x, n;

    x = 5; 
    n = 3;
    int v[3]; 
    v[0] = 1; 
    v[1] = 5;

    printf("%d\n", binsearch(x, v, n));
    printf("%d", binsearchnew(x, v, n));

}


int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1; 
        }
        else 
        {
            return mid; /* found matching value */
        }
    }
    return -1; /* no matching value */
}

int binsearchnew(int x, int v[], int n) 
{
    int low, high, mid;

    low = 0; 
    high = n - 1;

    mid = (low + high) / 2; 

    while (low <= high && x != v[mid]) 
    {
        if (x < v[mid])
        {
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }
        
        mid = (low + high) / 2;
    }

    if (x != v[mid]) 
    {
        return -1; 
    }
    else 
    {
        return mid;
    }
}