#include <stdio.h> 

char *month_name(int n); 

int main(int argc, char const *argv[])
{
    char *returnval;

    returnval = month_name(3);

    printf("%d", returnval);


}

/* month_name: return the name of nth month */
char *month_name(int n) 
{
    static char *name[] = {
        "Illegal month", 
        "January", "February", "March",
        "April", "May", "June", "July", 
        "August", "September", "Octorber",
        "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}