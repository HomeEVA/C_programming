#include <stdio.h> 
#include <string.h> 
#define MAXLINE 1000

int getlines(char *line, int max); 

/* find function: print all lines that contains the pattern */
int main(int argc, char *argv[]) 
{
    char line[MAXLINE]; 
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    //printf("%c\n", (*++argv)[2]);
    //printf("%c", *++argv[2]);
    while(--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'x': 
                    except = 1;
                    break;
                case 'n': 
                    number = 1; 
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if (argc != 1) {
        printf("Usage: find -x -n pattern\n");
    } else {
        while (getlines(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number) {
                    printf("%ld: ", lineno);
                }
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}

int getlines(char *lines, int maxlen) 
{
    int c, i; 
    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        *(lines + i) = c;
    }
    if (c == '\n') {
        *(lines + i) = c;
        ++i;
    }
    lines[i] = '\0';
    return i; 
}