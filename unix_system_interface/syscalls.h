#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

enum _flags {
    _READ = 01,
    _WRITE = 02,
    _UNBUF = 04,
    _EOF = 010, 
    _ERR = 020
};
#define OPEN_MAX 20 
#define EOF (-1)
#define BUFSIZ 1024
struct _iobuf 
{ 
    int cnt; 
    char *ptr;
    char *base; 
    int flag; 
    int fd; 
};
typedef struct _iobuf FILE;

extern FILE _iob[OPEN_MAX];

#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

#define getc(p) (--(p)->cnt >= 0 \
            ? (unsigned char) * (p)->ptr++ : _fillbuf(p))