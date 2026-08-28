#include <stdio.h>
#include "calc.h"
#define MAXVAL 100 

static int sp = 0;
static double val[MAXVAL];

/* push: put f into the stack */
void push(double f) 
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

/* pop: pop and return the value on top of the stack */
double pop(void) 
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear(void)
{
    sp = 0;
}