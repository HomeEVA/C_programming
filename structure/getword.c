#include <stdio.h> 
#include <ctype.h>
#include <string.h>

int comment(void);
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