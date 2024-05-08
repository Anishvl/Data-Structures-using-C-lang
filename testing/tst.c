#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

int inorder(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int middle = arr[size / 2];

    struct node *parent = malloc(sizeof(struct node));
    parent->data = middle;
    parent->left = NULL;
    parent->right = NULL;

    struct node *node1 = malloc(sizeof(struct node));
    node1->data = arr[0];
    node1->left = NULL;
    node1->right = NULL;
    parent->left = node1;

    struct node *node2 = malloc(sizeof(struct node));
    node2->data = arr[1];
    node2->left = NULL;
    node2->right = NULL;
    parent->right = node2;

    struct node *node3 = malloc(sizeof(struct node));
    node3->data = arr[2];
    node3->left = NULL;
    node3->right = NULL;
    node1->left = node3;

    struct node *node4 = malloc(sizeof(struct node));
    node4->data = arr[3];
    node4->left = NULL;
    node4->right = NULL;
    node1->right = node4;

    struct node *node5 = malloc(sizeof(struct node));
    node5->data = arr[4];
    node5->left = NULL;
    node5->right = NULL;
    node3->left = node5;

    printf("inorder: \n");
    inorder(parent);

    return 0;
}
