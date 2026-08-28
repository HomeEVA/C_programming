#include <stdio.h>
#include <stdlib.h> // to use atof()
#include <math.h>
#include "calc.h"

#define MAXOP 100 

int main(int argc, char const *argv[])
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER: 
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/': 
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push(fmod(pop(), op2));
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n': 
                printf("\t%.8g\n", pop());
                break;
            case 'p': // print the top element of the stack without poping the element
                op2 = pop(); 
                printf("%f", op2);
                push(op2);
                break;
            case 'd':
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's':
                op2 = pop();
                double op3 = pop();
                push(op2);
                push(op3);
                break;
            case 'c':
                clear();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
