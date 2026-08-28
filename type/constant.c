#include <stdio.h> 

// octonary number system 
#define VTAB '\013' 
#define BELL '\007'

//hexo number system 
#define VTAB1 '\xb'
#define BELL1 '\x7'

#define MAXLINE 1000 
char line[MAXLINE+1];

#define LEAP 1
int days[31 + 28 + LEAP + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31];

//enum 

enum boolean {NO, YES};
enum escapes {BELLS = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n',VTABS = '\v', RETURN = '\r'};

