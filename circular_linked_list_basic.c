#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
int main()
{
  struct node *head=malloc(sizeof(struct node));
  head->data=10;

  struct node *second=malloc(sizeof(struct node));
  second->data=20;

  struct node *third=malloc(sizeof(struct node));
  third->data=30;

  head->next=second;
  second->next=third;
  third->next=head;

  int n=0;
  struct node *current=head;
  while(n<=6)
    {
      printf("%d ",current->data);
      current=current->next;
      n++;
    }
}