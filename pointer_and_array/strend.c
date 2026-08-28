#include <stdio.h> 
#include <string.h>
int strend(char *s, char *t)
{
    /* TODO: 
    pre. store the address of first element 
    1. move to the last element of s 
    2. move to the last element of t 
    3. if last element not equal, return 0;
    4. while 
        a. move one element forward
        b. check if match: 
            b.1: no, return 0
            b.2: yes, continue loop (until reach the first element of t) 
            
    5. return 1*/ 

    char *q = t;
    if (strlen(s) < strlen(t)) {
        return 0;
    }
    
    s = s + strlen(s) - 1;
    t = t + strlen(t) - 1;
    
    if (*s-- != *t--) {
        return 0;
    }

    while(t != q) {
        if (*s-- == *t--) {
            ;
        } else {
            return 0;
        }
    }
    return 1;

}