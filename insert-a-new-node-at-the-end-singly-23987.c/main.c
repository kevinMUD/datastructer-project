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

// Function to insert a node after the tail
void insertAfterTail(Node **head, int data) {
    // Create the new node to be inserted
    Node *newNode = createNode(data);

    // If the list is empty, set the head to be the new node
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the end of the list to find the tail
    Node *tail = *head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    // Set the next pointer of the tail to be the new node
    tail->next = newNode;
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
    insertAfterTail(&head, 2);
    insertAfterTail(&head, 3);
    insertAfterTail(&head, 9);
    insertAfterTail(&head, 8);
    insertAfterTail(&head, 7);
    printList(head);
    return 0;
}
