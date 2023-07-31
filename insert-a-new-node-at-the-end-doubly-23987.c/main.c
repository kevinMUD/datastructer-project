#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
   struct Node* prev;
};

void insertNodeAtPosition(struct Node** head_ref, int position, int data) {
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   new_node->data = data;
   new_node->next = NULL;
   new_node->prev = NULL;
   if (*head_ref == NULL) {
      if (position == 1) {
         *head_ref = new_node;
      }
      else {
         printf("List is empty. Insertion not possible.");
         return;
      }
   }
   else if (position == 1) {
      new_node->next = *head_ref;
      (*head_ref)->prev = new_node;
      *head_ref = new_node;
   }
   else {
      int i;
      struct Node* temp = *head_ref;
      for (i = 1; i < position - 1 && temp != NULL; i++) {
         temp = temp->next;
      }
      if (temp == NULL) {
         printf("Position out of range. Insertion not possible.");
         return;
      }
      new_node->prev = temp;
      new_node->next = temp->next;
      if (temp->next != NULL) {
         temp->next->prev = new_node;
      }
      temp->next = new_node;
   }
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
   int data = 5;
   insertNodeAtPosition(&head, position, data);

   printf("\nList after inserting node with data %d at position %d: ", data, position);
   displayList(head);

   return 0;
}
