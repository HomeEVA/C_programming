#include <stdio.h>

void qsorts(int v[], int left, int right);

int v[] = {3, 2, 4, 1};

int main(int argc, char const *argv[]) 
{
    
    qsorts(v, 0, 3);

}

void qsorts(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right) {
        return;
    }

    swap(v, left, (left + right)/2);

    for (int t = 0; t < 4; t++) {
        printf("%d", v[t]);
    }

    printf("\n");

    last = left;
    for (i = left+1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);

            for (int t = 0; t < 4; t++) {
                printf("%d", v[t]);
                
            }
            printf("\n");
        }
    }
    swap(v, left, last); 
    for (int t = 0; t < 4; t++) {
        printf("%d", v[t]);
        
    }
    printf("\n");
    qsorts(v, left, last - 1);
    qsorts(v, last + 1, right);
}

void swap(int v[], int i, int j) 
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}