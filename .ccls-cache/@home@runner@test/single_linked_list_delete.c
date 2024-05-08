#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void delete(struct node *previous, struct node *current)
{
    previous->link = current->link;
    free(current);
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *second = malloc(sizeof(struct node));
    second->data = 20;
    second->link = NULL;
    head->link = second;

    struct node *third = malloc(sizeof(struct node));
    third->data = 30;
    third->link = NULL;
    second->link = third;

    struct node *forth = malloc(sizeof(struct node));
    forth->data = 40;
    forth->link = NULL;
    third->link = forth;

    struct node *fifth = malloc(sizeof(struct node));
    fifth->data = 50;
    fifth->link = NULL;
    forth->link = fifth;

    struct node *current = head;
    struct node *previous = NULL;

    while (current != NULL)
    {
        printf("Value: %d\n", current->data);
        current = current->link;
    }

    int a;
    printf("\nEnter the number to delete: ");
    scanf("%d", &a);

    current = head;
    previous = NULL;

    while (current != NULL)
    {
        if (current->data == a)
        {
            if (previous != NULL)
            {
                delete(previous, current);
            }
            else
            {
                head = current->link;
                free(current);
            }
            break; 
        }

        previous = current;
        current = current->link;
    }

    current = head;

    printf("\nLinked List after deletion:\n");
    while (current != NULL)
    {
        printf("Value: %d\n", current->data);
        current = current->link;
    }

    return 0;
}
