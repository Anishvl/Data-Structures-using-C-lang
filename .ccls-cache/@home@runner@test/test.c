//infix to postfix convertion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
void postfixconverter(char infix[],char postfix[])
{
  char stack[MAX];
  int top=-1;
}
int main()
{
  char a[100],b[100];
  printf("Enter the equation here");
  scanf("%s",a);
  printf("\nThe given equation\n");
  printf("%s\n",a);
  postfixconverter(a,b);
}