#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main (int argc, char *argv[])
{
    char *i = argv[1];
    int s = strlen(argv[argc-1]) - 1;
    char *j = argv[argc-1] + s;
    while (i < j) 
    {
        if (ispunct(*i) || *i == 0 || isspace(*i))
        {
            i++;
            continue;
        }
        
        if (ispunct(*j) || *j == 0 || isspace(*j))
        {
            j--;
            continue;
        }
        
        if (!(tolower(*i)==tolower(*j)))
        {
            printf("no\n");
            return 0;
        }
        i++;
        j--;
    }
    printf("yes\n");
    return 0;
}