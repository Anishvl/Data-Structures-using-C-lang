#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct stack
{
struct stack *top;
};
struct stack *createstack()
{
  struct stack *stack=malloc(sizeof(struct stack));
  stack->top=NULL;
  return stack;
}
void push(struct stack *stack,int data)
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=data;
  newnode->next=stack->top;
  stack->top=newnode;
}
void printstack(struct stack *stack)
{
  struct node *current =stack->top;
  printf("stacks:");
  while(current !=NULL)
    {
      printf("%d ",current->data);
      current=current->next;
    }
  printf("\n");
}
int main()
{
  int a;
    printf("Enter how many elements you want: ");
    scanf("%d", &a);
  printf("enter the elements\n");
  int arr[a];
  int i=0;
  while(i<a)
    {
     scanf("%d",&arr[i]);
      i++;
    }
  struct stack *stack=createstack();
  int j=0;
  while (j < a) {
    push(stack, arr[j]);
    j++;
}
  printstack(stack);
}