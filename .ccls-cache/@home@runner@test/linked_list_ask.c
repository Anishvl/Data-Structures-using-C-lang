#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    int n, value;
    struct node *head = NULL;
    struct node *current = NULL;

    printf("Enter how many elements you want in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the element %d: ", i + 1);
        scanf("%d", &value);

        struct node *newnode = malloc(sizeof(struct node));
        newnode->data = value;
        newnode->link = NULL;

        if (head == NULL)
        {
            head = newnode;
            current = head;
        }
        else
        {
            current->link = newnode;
            current = current->link;
        }
    }

    printf("\nLinked List: ");
    current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->link;
    }


    current = head;
    while (current != NULL)
    {
        struct node *temp = current;
        current = current->link;
        free(temp);
    }

    return 0;
}
