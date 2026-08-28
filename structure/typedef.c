#include <stdio.h>
#include <stdlib.h>
#define MAXLINES 1000
typedef int Length; 

Length len, maxlen;
Length *lengths[];

typedef char *String;

typedef struct tnode *Treeptr; 
typedef struct tnode {
    char *word;
    int count;
    Treeptr left; 
    Treeptr right;
} Treenode; 


typedef int (*PFI)(char *, char *); 
/*PFI is a pointer to a function, the function has two parameters, 
which are two pointers to char, the function returns an int*/ 

Treeptr talloc(void) 
{
    return (Treeptr) malloc(sizeof(Treenode));
}

int main (int argc, char const *argv[])
{
    String p, lineptr[MAXLINES];
    int strcmps(String, String);
    p = (String) malloc(100);
}

