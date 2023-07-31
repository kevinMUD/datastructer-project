#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct node {
    int data;
    struct node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a given position
void insertAtPosition(Node **head, int data, int position) {
    // Create the new node to be inserted
    Node *newNode = createNode(data);

    // If the list is empty or position is 0, set the head to be the new node
    if (*head == NULL || position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse to the node before the given position
    Node *current = *head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    // If the given position is beyond the end of the list, insert the new node at the end
    if (current == NULL) {
        current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    } else {
        // Insert the new node at the given position
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the linked list
void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Main function to test the linked list
int main() {
    Node *head = NULL;
    insertAtPosition(&head, 2, 0);
    insertAtPosition(&head, 3, 2);
    insertAtPosition(&head, 9, 3);
    insertAtPosition(&head, 8, 9);
    insertAtPosition(&head, 7, 8);
    printList(head);
    return 0;
}
