#include <stdio.h> 
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0, 
    "break", 0, 
    "case", 0, 
    "char", 0, 
    "const", 0,
    "continue", 0,
    /* ... */
    "unsigned", 0,
    "void", 0, 
    "volatile", 0, 
    "while", 0, 
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

#define NKEYS (sizeof keytab / sizeof (struct key))

int main (int argc, char const *argv[]) 
{
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
                keytab[n].count++;
            }
        }
    }
    for (n = 0; n < NKEYS; n++) {
        if (keytab[n].count > 0) {
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
        }
    }
    return 0;
}

/* binsearch: search word between tab[0] and tab[n-1] */
int binsearch(char *word, struct key tab[], int n) 
{
    int cond;
    int low, high, mid;

    low = 0; 
    high = n - 1; 
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0) {
            high = mid - 1;
        } 
        else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int getword(char *word, int lim) 
{
    int c, d, comment(void); 
    char *w = word;

    while (isspace(c = getchar())) {
        ; //skip all spaces
    }
    if (c != EOF) {
        *w++ = c;
    }
    if (isalpha(c) || c == '_' || c == '#') {
        for (; --lim > 0; w++) {
            if (!isalnum(*w = getchar()) && *w != '_') {
                ungetc(*w, stdin);
                break;
            
            }
        }
    } else if ( c == '\'' || c == '"') {
        for (; --lim > 0; w++) {
            if ((*w = getchar()) == '\\') {
                *++w = getchar();
            } else if (*w == c) {
                ungetc(*w, stdin);
                break;
            } else if (*w == EOF) {
                break;
            }
        }

    } else if (c == '/') {
        if ((d = getchar()) == '*') {
            c = comment();
        } else {
            ungetc(d, stdin);
        }
    }
    
    *w = '\0';
    return c;
}

int comment (void)
{
    int c; 
    while((c = getchar()) != EOF) {
        if (c == '*') {
            if ((c = getchar()) == '/') {
                break;
            } else {
                ungetc(c, stdin);
            }
        }
    }
    return c;
}
