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

// Function to delete a node at a given position
void deleteNode(Node **head, int position) {
    if (*head == NULL) {
        return;
    }

    Node *current = *head;

    // If the head
