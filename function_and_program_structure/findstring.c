#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int max);
int strindex(char source[], char searchfor[]);
int newstrindex(char s[], char t[]);

char pattern[] = "ould";

int main(int argc, char const *argv[])
{
    //char line[MAXLINE];
    //int found = 0;

    //while (getlines(line, MAXLINE) > 0) {
       // if (strindex(line, pattern) >= 0) {
            //printf("%s", line);
            //found++;
        //}
    //}

    //return found; 
    char s[] = "Yes I should should";
    printf("%d", newstrindex(s, pattern));
}


/* getline: save the current line into array s, 
return length of line*/
int getlines(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    if (c =='\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

/* strindex: return string t 's position in s, if not found, return -1 */
int strindex(char s[], char t[]) 
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            return i;
        }
        
    }
    return -1;
}

int newstrindex(char s[], char t[])
{
    int i, j, k, c; 

    c = 0;
    
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; s[i] != '\0' && s[j] == t[k]; j++, k++){
            ;
        }
        if (k > 0 && t[k] == '\0') {
            c = i; 
        }
        
    }

    if (c == 0) {
        return -1;
    } else {
        return c;
    }
    
    
    
}