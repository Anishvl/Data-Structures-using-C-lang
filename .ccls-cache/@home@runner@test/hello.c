#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};


struct node *createLinkedList(int numNodes) {
  struct node *head = NULL;
  struct node *current = NULL;

  for (int i = 0; i < numNodes; i++) {
    struct node *newNode = malloc(sizeof(struct node));
    printf("Enter the value for node %d: ", i + 1);
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    newNode->prev = current;

    if (current != NULL) {
      current->next = newNode;
    }

    current = newNode;

    if (head == NULL) {
      head = newNode;
    }
  }

  return head;
}


void printLinkedList(struct node *head) {
  struct node *current = head;
  printf("Forward elements: ");
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  int numNodes;
  printf("Enter the number of nodes: ");
  scanf("%d", &numNodes);

  struct node *head = createLinkedList(numNodes);


  printLinkedList(head);

  struct node *current = head;
  while (current != NULL) {
    struct node *temp = current;
    current = current->next;
    free(temp);
  }

  return 0;
}
