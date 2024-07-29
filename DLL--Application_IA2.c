#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char USN[10];
    int CE;
    struct Node* next;
    struct Node* prev;
};

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;
    struct Node* fifth = NULL;

    // Allocate memory for nodes
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Assign values and link nodes
    strcpy(head->name, "Alice");
    strcpy(head->USN, "1RV17CS001");
    head->CE = 85;
    head->next = second;
    head->prev = NULL;

    strcpy(second->name, "Bob");
    strcpy(second->USN, "1RV17CS002");
    second->CE = 90;
    second->next = third;
    second->prev = head;

    strcpy(third->name, "Charlie");
    strcpy(third->USN, "1RV17CS003");
    third->CE = 88;
    third->next = fourth;
    third->prev = second;


    // Print the list
    struct Node* temp = head;
    printf("Doubly Linked List:\n");
    while (temp != NULL) {
        printf("Name: %s, USN: %s, CE: %d\n", temp->name, temp->USN, temp->CE);
        temp = temp->next;
    }

    // Find the node with the highest CE
    struct Node* highest = head;
    temp = head;
    while (temp != NULL) {
        if (temp->CE > highest->CE) {
            highest = temp;
        }
        temp = temp->next;
    }

    // Print the node with the highest CE
    if (highest != NULL) {
        printf("\nNode with the highest CE:\n");
        printf("Name: %s, USN: %s, CE: %d\n", highest->name, highest->USN, highest->CE);
    } else {
        printf("The list is empty.\n");
    }

    // Free the allocated memory
    free(head);
    free(second);
    free(third);
  
    return 0;
}

