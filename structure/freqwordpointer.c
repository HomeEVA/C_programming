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
struct key *binsearch(char *, struct key *, int);

#define NKEYS (sizeof keytab / sizeof (struct key))

int main(int argc, char const *argv[])
{
    char word[MAXWORD];
    struct key *p;
    
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            if ((p=binsearch(word, keytab, NKEYS)) != NULL) {
                p -> count++; 
            }
        }
    }
    for (p = keytab; p < keytab + NKEYS; p++) {
        if (p -> count > 0) {
            printf("%4d %s\n", p -> count, p -> word);
        }
    }
    return 0;
}

struct key *
binsearch(char *word, struct key *tab, int n) 
{
    int cond; 
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid -> word)) < 0) {
            high = mid; 
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return NULL;
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
