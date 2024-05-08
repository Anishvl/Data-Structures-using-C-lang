#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
int delete(struct node *previous, struct node *current)
{
    previous->link = current->link;
    free(current);
    return 1; 
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *second = malloc(sizeof(struct node));
    second->data = 46;
    second->link = NULL;
    head->link = second;

    struct node *current = head;
    while (current != NULL)
    {
        printf("%d--", current->data);
        current = current->link;
    }
    printf("NULL");

    int a;
    printf("\nEnter the number to delete: ");
    scanf("%d", &a);
    struct node *previous = NULL;
    current = head;
  while(current!=NULL)
    {
      if(current->data==a)
      {
        if(previous != NULL)
        {
          if(delete(previous,current))
          {
            printf("\nSucessfully deleted %d \n",a);
          }
          else
          {
           printf("\nfailed to delete %d \n",a);
          }
        }
        else
        {
          head=current->link;
          free(current);
        }
        break;
      }
      previous=current;
      current=current->link;
    }

  printf("\nThe linked list after deletion:\n");
    current = head; // Reset current to the beginning of the list
    while (current != NULL)
    {
        printf("%d--", current->data);
        current = current->link;
    }
    printf("NULL\n");

    return 0;
}
