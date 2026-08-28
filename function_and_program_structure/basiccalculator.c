#include <stdio.h>
#include <stdlib.h> // to use atof()
#include <math.h>

#define MAXOP 100 
#define NUMBER '0'


int getop(char[]);
void push(double);
double pop(void);
void clear(void);

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

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

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

#include <ctype.h>

int getch(void);
void ungetch(int); 

int getop(char s[]) {
    int i, c; 

    while ((s[0] = c = getchar()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    if (c == '-') {
        if (isdigit(c = getchar()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                ungetch(c);
            }
            return '-';
        }
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }

    return NUMBER; 
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch function */
int bufp = 0; /* the next free spot in buf */

int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* put char back into the buffer */
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else { 
        buf[bufp++] = c;
    }
}