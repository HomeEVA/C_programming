#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
    char *word;             /* pointer to word */
    int count;              /* count of how many times word appear */ 
    struct tnode *left;     /* left sub-tnode */
    struct tnode *right;    /* right sub-tnode */
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
extern int getword(char *, int); 
void freetree(struct tnode *);

int main(int argc, char const *argv[]) 
{
    struct tnode *root; 
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    freetree(root);
    return 0;
}

struct tnode *talloc(void) 
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}
char *strdups(char *s) 
{
    char *p;

    p = (char *) malloc(strlen(s) + 1); 
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;

}

struct tnode *addtree(struct tnode *p, char *w)
{
    int cond; 

    if (p == NULL) {    /* if it is a new word */
        p = talloc();   /* create a new tnode */
        p -> word = strdups(w);
        p -> count = 1;
        p ->left = p -> right = NULL;
    } else if ((cond = strcmp(w, p -> word)) == 0) {
        p -> count++;   /* new word matches the word at current tnode p */
    } else if (cond < 0) {
        p -> left = addtree(p -> left, w);  /* if new word smaller than word at tnode p, enter left sub-tree */
    } else {
        p -> right = addtree(p -> right, w); /* if new word greater than word at tnode p, enter right sub-tree */
    }
    return p;
}

void treeprint(struct tnode *p) 
{
    if (p != NULL) {
        treeprint(p -> left);
        printf("%4d %s\n", p -> count, p -> word);
        treeprint(p -> right);
    }
}

void freetree(struct tnode *p) 
{
    if (p == NULL) {
        return;
    }

    freetree(p -> left);
    freetree(p -> right);
    free(p -> word);
    free(p);
}