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

// Function to delete the last node in the list
void deleteLastNode(Node **head) {
    // If the list is empty or has only one node, delete the head node
    if (*head == NULL || (*head)->next == NULL) {
        *head = NULL;
        return;
    }

    // Traverse to the node before the last node
    Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Free the memory allocated to the last node
    free(current->next);
    current->next = NULL;
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
    head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(9);
    head->next->next->next = createNode(8);

    printf("List before deleting the last node: ");
    printList(head);

    deleteLastNode(&head);

    printf("List after deleting the last node: ");
    printList(head);

    return 0;
}
