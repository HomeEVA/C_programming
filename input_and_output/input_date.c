#include <stdio.h> 

int main(int argc, char const *argv[]) 
{
    int day, year, month; 
    char monthname[20];
    
    /* method 1 */
    //scanf("%d %s %d", &day, monthname, &year);
    //scanf("%d/%d/%d", &month, &day, &year);

    //printf("%d/%d/%d", month, day, year);

    char *line = NULL;
    size_t len = 0;

    while(getline(&line, &len, stdin) > 0) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3) {
            printf("valid: %s\n", line);
        } else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) {
            printf("valid: %s\n", line);
        } else {
            printf("invalid: %s\n", line);
        }
    }
}