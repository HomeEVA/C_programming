#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...) 
{
    va_list ap; /* points to nameless parameter (in order) */
    char *p, *sval;
    int ival; 
    double dval;

    va_start(ap, fmt); /* points ap to the first nameless parameter */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f",dval);
                break;
            case 's': 
                for (sval = va_arg(ap, char *); *sval; sval++) {
                    putchar(*sval);
                    
                }
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* clean when end */
}

int main(int argc, char const *argv[])
{
    int s = 3;
    char *mystring = "yes";
    minprintf("%d", 3);
    minprintf("%s",mystring);
}