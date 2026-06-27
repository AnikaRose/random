#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d -> ", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the front of the list
void insertAtHead(struct Node** head_ref, int new_data) {
    // 1. Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // 2. Put in the data
    new_node->data = new_data;
    
    // 3. Make next of new node as head
    new_node->next = (*head_ref);
    
    // 4. Move the head to point to the new node
    *head_ref = new_node;
}

int main() {
    // Start with an empty list
    struct Node* head = NULL;

    // Insert elements
    insertAtHead(&head, 40);
    insertAtHead(&head, 30);
    insertAtHead(&head, 20);
    insertAtHead(&head, 10);

    printf("Created Linked List:\n");
    printList(head);

    // Free allocated memory to prevent memory leaks
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}