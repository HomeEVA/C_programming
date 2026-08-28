#include <stdio.h> 

void shellsort(int v[], int n);

int main(int argc, char const *argv[])
{
    int v[4]; 
    int n = 4;
    v[0] = 3; 
    v[1] = 1;
    v[2] = 5;
    v[3] = 4;
    shellsort(v, n);
}

void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for(j = i - gap; j >=0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}