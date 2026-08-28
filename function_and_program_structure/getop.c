#include <stdio.h>
#include <ctype.h>
#include "calc.h"

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