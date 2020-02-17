#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *out;
    char *in = argv[1];
    int argSize = strlen(in);
    out = malloc(sizeof(char) * (argSize) + 1);
    int ptr = 0;
    int argPtr = 0;
    int count = 1;
    while (argPtr < argSize)
    {
        if (isdigit(*(in + argPtr)))
        {
            printf("error\n");
            free(out);
            return 0;
        }
        argPtr++;
    }
    argPtr = 0;
    while (ptr < argSize - 1)
    {
        char c = *(in + argPtr);
        *(out + ptr) = c;
        while (*(in + argPtr + 1) == c)
        {
            argPtr++;
            count++;
        }
        ptr++;
        if (count > 9)
        {
            int countPlaces = 0;
            int tempcount = count;
            while (tempcount > 0)
            {
                countPlaces++;
                tempcount /= 10;
            }
            char *digits = malloc(countPlaces + 1);
            sprintf(digits, "%i", count);
            int i = 0;
            while (i < strlen(digits))
            {
                *(out + ptr) = *(digits + i);
                ptr++;
                i++;
            }
            free(digits);
        }
        else
        {
            *(out + ptr) = count + '0';
            ptr++;
        }
        count = 1;
        if (argPtr == argSize - 1)
        {
            *(out + ptr) = '\0';
            printf("%s\n", out);
            free(out);
            return 0;
        }
        argPtr++;
    }
    printf("%s\n", in);
    free(out);
    return 0;
}