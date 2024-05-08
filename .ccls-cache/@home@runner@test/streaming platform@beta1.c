#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
char song[100];
char title[100];
struct node *next;
};

struct node *createstack(char* song,char* title)
{
  struct node *newnode=malloc(sizeof(struct node));
  strcpy(newnode->song,song);
  strcpy(newnode->title,title);
  newnode->next=NULL;
  return newnode;
}

void display(struct node *head)
{
  struct node *current=head;
  while(current!=NULL)
    {
      printf("%s ",current->song);
      current=current->next;
    }
  while(current!=NULL)
    {
      printf("%s ",current->title);
      current=current->next;
    }
}

int main() {
    struct SongInfo* head = NULL;

    char song[100], title[100];

    printf("Enter the song name: ");
    scanf("%s", song);

    printf("Enter the artist name: ");
    scanf("%s", title);
  head=createstack(song,title);
  display(head);
}