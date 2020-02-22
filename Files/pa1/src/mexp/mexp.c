#include <stdio.h>
#include <stdlib.h>
#define debug 0
int main(int argc, char *argv[])
{
    FILE *f = NULL;
    if (!debug)
        f = fopen(argv[1], "r");
    else
    {
        f = fopen("C:\\Users\\Derek\\Desktop\\211 Assignment 1\\PA1\\Files\\pa1\\src\\mexp\\file.txt", "r");
    }
    
    //printf("File opened\n");
    int i = 0, l = 0;
    if (f == NULL)
    {
        printf("File not read\n");
        return 0;
    }
    fscanf(f, "%i", &i);
    //printf("Scanned int\n");
    int *matrix = (int *)malloc(sizeof(int) * i * i);
    int *original = (int *)malloc(sizeof(int) * i * i);
    int *storage  = (int *)malloc(sizeof(int) * i * i);
    //printf("Matrix created\n");
    int j, k;
    j = k = 0;
    for (j = 0; j < i; j++)
    {
        for (k = 0; k < i; k++)
        {
            fscanf(f, "%i", &l);
            *(matrix + j * i + k) = l;
            *(original + j * i + k) = l;
        }
    }
    fscanf(f, "%i", &l);
    if (l == 0)
    {
        for (j = 0; j < i; j++)
        {
            for (k = 0; k < i; k++)
            {
                if (j == k)
                {
                    *(matrix + j * i + k) = 1;
                }
                else
                {
                    *(matrix + j * i + k) = 0;
                }
                printf("%i", *(matrix + j * (i) + k));
                if (k + 1 < i)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    else
    {
        
        while (l > 1)
        {
            for (j = 0; j < i; j++)
            {
                for (k = 0; k < i; k++)
                {
                    int h = 0;
                    int sum = 0;
                    while (h <i)
                    {
                        sum += (*(matrix + j * i + h) * *(original + h * i + k));
                        h++;
                    }
                    *(storage + j*i + k) = sum;
                    
                }
               
            }
            for (j = 0; j < i; j++)
            {
                for (k = 0; k<i; k++)
                {
                    *(matrix + j*i + k) = *(storage + j*i + k);
                    
                }
            }
            l--;
        }
    }
    for (j = 0; j < i; j++)
    {
        for (k = 0; k < i; k++)
        {
            printf("%i", *(matrix + j*i + k));
            if (k + 1 < i)
                {
                    printf(" ");
                }
        }
        printf("\n");
    }
    free(storage);
    free(matrix);
    free(original);
    return 0;
}