#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};

void deleteLastNode(struct Node** head_ref) {
   if (*head_ref == NULL) {
      printf("List is empty.");
      return;
   }
   if ((*head_ref)->next == NULL) {
      free(*head_ref);
      *head_ref = NULL;
      return;
   }
   struct Node* last = *head_ref;
   while (last->next != NULL) {
      last = last->next;
   }
   last->prev->next = NULL;
   free(last);
}

void displayList(struct Node* node) {
   while (node != NULL) {
      printf("%d ", node->data);
      node = node->next;
   }
}

int main() {
   struct Node* head = NULL;
   struct Node* second = NULL;
   struct Node* third = NULL;
   struct Node* fourth = NULL;

   // allocate memory for nodes
   head = (struct Node*)malloc(sizeof(struct Node));
   second = (struct Node*)malloc(sizeof(struct Node));
   third = (struct Node*)malloc(sizeof(struct Node));
   fourth = (struct Node*)malloc(sizeof(struct Node));

   // assign data values
   head->data = 1;
   second->data = 2;
   third->data = 3;
   fourth->data = 4;

   // connect nodes
   head->prev = NULL;
   head->next = second;
   second->prev = head;
   second->next = third;
   third->prev = second;
   third->next = fourth;
   fourth->prev = third;
   fourth->next = NULL;

   printf("Original List: ");
   displayList(head);

   deleteLastNode(&head);

   printf("\nList after deleting last node: ");
   displayList(head);

   return 0;
}
