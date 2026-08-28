#define ALLOCSIZE 10000 /* available space */

static char allocbuf[ALLOCSIZE]; /* storage space alloc use */
static char *allocp = allocbuf;  /* the next free space */

char *alloc(int n);
void afree(char *p); 

int main(int argc, char const *argv[])
{
    //
}


char *alloc(int n) 
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n; /* pointer p before allocation */
    } else {
        return 0;
    }
}

void afree(char *p) /* release the storage area p points to */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
        allocp = p;
    }
}