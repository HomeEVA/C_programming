#include <unistd.h>
#include <stdio.h>

#undef getchar
#define BUFSIZE 1024

int getchar1(void);
int getchar2(void);
int main(int argc, char const *argv[])
{
    //char buf[BUFSIZE];
    //int n;

    //while ((n = read(0, buf, BUFSIZE)) > 0) {
       // write(1, buf, n);
   // }
    //return 0;

    printf("%c\n", getchar2());
    printf("%c", getchar2());
    printf("%c", getchar2());
    printf("%c", getchar2());
    printf("%c", getchar2());
}


/* getchar1: one char input, no buffer */
int getchar1(void) 
{
    char c;
    
    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

/*getchar2: simple buffer version */
int getchar2(void) 
{
    static char buf[BUFSIZE];
    static char *bufp = buf; 
    static int n = 0;

    if (n == 0) { // buffer empty
        n = read(0, buf, sizeof buf); 
        bufp =  buf; 
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}