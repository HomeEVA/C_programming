#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* define an array, always point to the same address, 
    can change each single char inside the array */
    char amessage[] = "now is the time";

    /* define a pointer, can change to point to other address, 
    will not result in anything if try to alter the content 
    of string it points to */    
    char *pmessage = "now is the time";
}