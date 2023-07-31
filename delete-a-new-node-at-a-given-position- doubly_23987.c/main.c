#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};

void deleteNodeAtPosition(struct Node** head_ref, int position) {
   if (*head_ref == NULL) {
      printf("List is empty.");
      return;
   }
   struct Node* temp = *head_ref;
   if (position == 1) {
      *head_ref = temp->next;
      if (*head_ref != NULL) {
         (*head_ref)->prev = NULL;
      }
      free(temp);
      return;
   }
   int i;
   for (i = 1; temp != NULL && i < position; i++) {
      temp = temp->next;
   }
   if (temp == NULL) {
      printf("Position out of range.");
      return;
   }
   temp->prev->next = temp->next;
   if (temp->next != NULL) {
      temp->next->prev = temp->prev;
   }
   free(temp);
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

   int position = 3;
   deleteNodeAtPosition(&head, position);

   printf("\nList after deleting node at position %d: ", position);
   displayList(head);

   return 0;
}
