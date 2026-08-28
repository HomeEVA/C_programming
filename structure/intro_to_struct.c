#include <stdio.h>
#include <math.h>
struct point {
    int x;
    int y;
};

struct point pt; /* define a variable of type struct point */
struct point maxpt = { 320, 200 };

struct rect {
    struct point pt1;
    struct point pt2;
};

struct rect screen = {{0, 0}, {320, 200}};
int main(int argc, char const *argv[]) 
{
    printf("%d,%d\n", pt.x, pt.y);

    double dist; 

    dist = sqrt((double)maxpt.x * maxpt.x + (double)maxpt.y * maxpt.y);
    printf("%e\n", dist);
    printf("%f\n", dist);
    printf("%d\n", screen.pt1.x);
    printf("%d\n", screen.pt2.y - screen.pt2.x);
}