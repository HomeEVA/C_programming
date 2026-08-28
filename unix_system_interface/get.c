#include <unistd.h>
#include <stdio.h>
#define BUFSIZE 1024

static char buf[BUFSIZE];
int get(int fd, long pos, char *buf, int n);

int main (int argc, char const *argv[]) 
{
    printf("%d", get(0, 0, buf, 3));
}

int get(int fd, long pos, char *buf, int n)
{
    if (lseek(fd, pos, 0) >= 0 ) {
        return read(fd, buf, n);
    } else {
        return -1;
    }
}