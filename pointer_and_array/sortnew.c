#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAXLINE 5000 
char *lineptr[MAXLINE]; /* pointer points to lines of string */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[],int nlines);

void qsorts(void *lineptr[], int left, int right, 
    int (*comp)(void *, void *));
int numcmp(char *, char *);

int main(int argc, char const *argv[])
{
    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n")) {
        numeric = 1;
    }
    if ((nlines = readlines(lineptr, MAXLINE)) >= 0) {
        qsorts((void **)lineptr, 0, nlines -1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

void qsorts(void *v[], int left, int right, 
    int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) { /* if element of array smaller than 2, do nothing */
        return;
    }

    swap(v, left, (left + right)/2);
    last = left; 
    for (i = left+1; i<= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsorts(v, left, last - 1, comp);
    qsorts(v, last+1, right, comp);
}

int numcmp(char *s1, char *s2) 
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } 
    else if (v1 > v2) {
        return 1; 
    } else {
        return 0;
    }
}

void swap(void *v[], int i, int j) 
{
    void *temp;

    temp = v[i];
    v[i] = v[j]; 
    v[j] = temp;
}

#define MAXLEN 1000
char *alloc(int);
int getline2(char *lines, int maxlen);
int readlines(char *lineptr[], int maxlines) {
    
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while((len = getline2(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) 
{
    int i; 
    
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

int getline2(char *lines, int maxlen) 
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