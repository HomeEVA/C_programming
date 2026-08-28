#include <stdio.h>

enum {EXIT_SUCCESS = 0, EXIT_CANNOT_OPEN = 1, EXIT_WRITE_ERROR = 2};
/* cat: connect multiple files, verison 2 */
int main(int argc, char const *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];   /* record program name, for error handling */

    if (argc == 1) {
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(EXIT_WRITE_ERROR);
    }
    exit(EXIT_SUCCESS);
}

/* filecopy: copy file ifp into file ofp */
void filecopy(FILE *ifp, FILE *ofp) 
{
    int c; 
    
    while ((c = getc(ifp)) != EOF) {
       if(putc(c, ofp) == EOF) {
        fprintf(stderr, "filecopy: write error\n");
        exit(EXIT_WRITE_ERROR);
       }
    }
}