#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;
    head->prev = NULL;

    struct node *second = malloc(sizeof(struct node));
    second->data = 20;
    second->next = NULL;
    second->prev = head;
    head->next = second;

    struct node *current = head;
    printf("Forward elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("Backward elements: ");
    struct node *prevs = second;
    while (prevs != NULL)
    {
        printf("%d ", prevs->data);
        prevs = prevs->prev;
    }
    printf("NULL\n");

    printf("After adding:\n");
    struct node *third = malloc(sizeof(struct node));
    third->data = 30;
    third->next = NULL;
    third->prev = second;
    second->next = third;

    struct node *currentt = head;
    printf("Forward elements: ");
    while (currentt != NULL)
    {
        printf("%d ", currentt->data);
        currentt = currentt->next;
    }
    printf("NULL\n");

    printf("Backward elements: ");
    struct node *prevss = third;
    while (prevss != NULL)
    {
        printf("%d ", prevss->data);
        prevss = prevss->prev;
    }
    printf("NULL\n");


    free(head);
    free(second);
    free(third);

    return 0;
}
