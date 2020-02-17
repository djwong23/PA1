#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define DEBUG 1

struct Node
{
    int num;
    struct Node *next;
};

int main(int argc, char *argv[])
{
    char input[20];
    char c;
    int i;
    int count;
    struct Node *root = NULL;
    while (1)
    {

        if (fgets(input, 20, stdin) == NULL)
            break;
        sscanf(input, "%c %d", &c, &i);

        if (c == 'i')
        {
            if (root == NULL)
            {
                root = malloc(sizeof(struct Node));
                root->num = i;
                root->next = NULL;
                count = 1;
            }

            else
            {
                if (i < root->num)
                {
                    struct Node *p = malloc(sizeof(struct Node));
                    p->num = i;
                    p->next = root;
                    root = p;
                    count++;
                }
                else
                {
                    struct Node *ptr = root;

                    while (ptr != NULL)
                    {
                        if (ptr->num == i)
                        {
                            break;
                        }
                        if (ptr->next == NULL)
                        {
                            if (i < ptr->num)
                            {
                                struct Node *new = malloc(sizeof(struct Node));
                                new->num = i;
                                new->next = ptr;
                                count++;
                                break;
                            }
                            else
                            {
                                struct Node *new = malloc(sizeof(struct Node));
                                new->num = i;
                                new->next = NULL;
                                ptr->next = new;
                                count++;
                            }
                        }
                        else if (ptr->next != NULL)
                        {
                            if (i > ptr->num && i < ptr->next->num)
                            {
                                struct Node *p = ptr->next;
                                struct Node *new = malloc(sizeof(struct Node));
                                new->num = i;
                                new->next = p;
                                ptr->next = new;
                                count++;
                                break;
                            }
                        }
                        ptr = ptr->next;
                    }
                }
            }
        }
        else
        {
            break;
        }
        struct Node *ptr = root;
        printf("%i : ", count);
        while (ptr != NULL)
        {
            printf("%i ", ptr->num);
            ptr = ptr->next;
        }
    }
    struct Node *p = NULL;
    struct Node *ptr = root;
    while (ptr != NULL)
    {
        p = ptr;
        ptr = ptr->next;
        free(p);
    }
    return 0;
}

/*
    struct Node *out = malloc(sizeof(struct Node));
    out->num = 1;
    //printf("%i\n",out->num);
    out->next = malloc(sizeof(struct Node));
    out->next->num = 2;
    out->next->next = NULL;
    //int f = out->next->num;
    //printf("%i\n",f);
    struct Node *ptr = out;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->num);
        ptr = ptr->next;
    }
    struct Node *p = NULL;
    ptr = out;
    while (ptr != NULL)
    {
        p = ptr;
        ptr = ptr->next;
        free(p);

    }
    */
