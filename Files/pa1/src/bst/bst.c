#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int num;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *root, int num)
{
    if (root == NULL)
    {
        root = malloc(sizeof(struct Node));
        root->num = num;
        root->left = NULL;
        root->right = NULL;
        printf("inserted\n");
    }
    else if (num < root->num)
    {
        root->left = insert(root->left, num);
    }
    else if (num > root->num)
    {
        root->right = insert(root->right, num);
    }
    else
    {
        printf("not inserted\n");
    }

    return root;
}

int search(struct Node *root, int num)
{
    if (root != NULL)
    {
        if (root -> num == num)
        {
            return 1;
        }

        if (num < root->num)
        {
            return search(root->left, num);
        }
        else if (num > root->num)
        {
            return search(root->right, num);
        }
    }
    
        return 0;
    
    
}

void print(struct Node *root)
{
    if (root == NULL)
        return;
    printf("(");
    print(root->left);
    printf("%i", root->num);
    print(root->right);
    printf(")");
}

struct Node* delete(struct Node *root, int num)
{
    if (root == NULL)
    {
        return root;
    }
    if (num < root-> num)
    {
        root->left = delete(root->left, num);
    }
    else if (num > root-> num)
    {
        root->right = delete(root->right, num);
    }
    else
    {
        if (root->left == NULL && root-> right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root -> right == NULL)
        {
            struct Node* n = root->left;
            free(root);
            return n;
        }
        else if(root-> left == NULL)
        {
            struct Node* n = root->right;
            free(root);
            return n;
        }
        else
        {
            struct Node *parent = root->left;
            struct Node *ptr = root->left->right;
            if (ptr == NULL)
            {
                root->left = NULL;
                parent->right = root->right;
                free(root);
                free(ptr);
                return parent;
            }
            else
            {
                while (ptr->right != NULL)
                {
                    parent = ptr;
                    ptr = ptr->right;
                }
                parent->right = NULL;
                ptr->right = root->right;
                ptr->left = root->left;
                free(root);
                return ptr;
            }
        }
        

    }
    return root;
}

void freeAll(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    freeAll(root->left);
    freeAll(root->right);
    free(root);
}

int main()
{
    char input[20];
    char c;
    int i;
    struct Node *root = NULL;
    while (1)
    {
        if (fgets(input, 20, stdin) == NULL)
            break;
        sscanf(input, "%c %d", &c, &i);
        if (c == 'i')
        {
            root = insert(root, i);
        }
        else if (c == 's')
        {
            if(search(root, i) == 1)
            {
                printf("present\n");
            }
            else
            {
                printf("absent\n");
            }
            
        }
        else if (c == 'p')
        {
            print(root);
            printf("\n");
        }
        else if (c == 'd')
        {
            if (search(root, i) == 1)
            {
                root = delete(root, i);
                printf("deleted\n");
            }
            else
            {
                printf("absent\n");
            }
            
        }
        else
        {
            break;
        }
    }

    freeAll(root);
    return 0;
}