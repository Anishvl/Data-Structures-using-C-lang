#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *next;
};

int main()
{
  int nums;
  printf("enter how many nodes you want?");
  scanf("%d",&nums);
  if(nums<=0)
  {
    return NULL;
  }

  struct node *head=NULL;
  struct node *current=NULL;

  for(int i=0;i<nums;i++)
    {
      struct node *newnode=malloc(sizeof(struct node));
      printf("\nenter the number for %d node\n",i+1);
      scanf("%d",&newnode->data);
      newnode->next=NULL;

      if(current==NULL)
      {
        head=newnode;
        current=newnode;
      }
      else{
        current->next=newnode;
        current=newnode;
      }
    }
  if(current!=NULL)
  {
    current->next=head;
  }
  int i=0;
   current=head;
  while(i<nums+1)
    {
      printf("%d--",current->data);
      current=current->next;
      i++;
    }
}