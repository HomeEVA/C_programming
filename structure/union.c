#include <stdio.h>
#define NSYM 4
enum {INT, FLOAT, STRING};
union u_tag {
    int ival; // 4 byte
    float fval;  // 4 byte
    char *sval; // 8 byte 
} u; 

struct {
    char *name; 
    int flags; 
    int utype; 
    union {
        int ival; 
        float fval; 
        char *sval; 
    }u;
} symtab[NSYM];

int main(int argc, char const *argv[]) 
{
    printf("the union occupies %zu bytes", sizeof(u));

    if (utype == INT) {
        printf("%d\n", u.ival);
    } else if (utype == FLOAT) {
        printf("%f\n", u.fval);
    } else if (utype == STRING) {
        printf("%s\n", u.sval);
    } else {
        printf("bad type %d in utype\n", utype); 
    }
    return 0;
}