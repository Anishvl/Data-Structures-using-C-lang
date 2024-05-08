#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *secondNode = malloc(sizeof(struct node));
    secondNode->data = 95;
    secondNode->link = NULL;

    head->link = secondNode;
    struct node *current = head;
    while (current != NULL)
    {
        printf("Value: %d\n", current->data);
        current = current->link;
    }

    free(head);
    free(secondNode);
}
