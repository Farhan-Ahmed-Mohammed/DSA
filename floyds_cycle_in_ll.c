#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert at head of a circular linked list
struct Node *insertAtHead(int x, struct Node* head) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated\n");
        return head;
    }

    newNode->data = x;

    if (head == NULL) {
        newNode->next = newNode; 
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

// Function to detect loop in the linked list
struct Node* detect(struct Node* head) {
    if (head == NULL) {
        printf("Empty list\n");
        return NULL;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    // Detect loop using fast and slow pointers
    do {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow; // Loop detected
        }
    } while (fast != head && fast->next != head);

    return NULL; // No loop detected
}

// Function to find the starting node of the loop
struct Node* startingNode(struct Node* head) {
    struct Node* intersection = detect(head);
    if (intersection == NULL) return NULL; // No loop

    struct Node* slow = head;
    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow; // Starting point of the loop
}

// Function to remove the loop and convert circular linked list to singly linked list
struct Node* removeLoop(struct Node* head) {
    struct Node* startOfLoop = startingNode(head);
    if (startOfLoop == NULL) {
        printf("No loop to remove\n");
        return head;
    }

    struct Node* temp = startOfLoop;
    while (temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL; // Break the loop
    return head;
}

// Function to print the list (handles both circular and non-circular)
void print(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;

        // Stop if we detect that we've looped back to the head (for circular lists)
        if (temp == head) {
            break;
        }
    }
}

int main() {
    struct Node *head = NULL;
    head = insertAtHead(30, head);
    head = insertAtHead(25, head);
    head = insertAtHead(35, head);
    head = insertAtHead(15, head);

    printf("Initial List:\n");
    print(head);

    // Detect loop
    if (detect(head) != NULL) {
        printf("Loop detected\n");
    } else {
        printf("No loop detected\n");
    }

    // Remove loop
    head = removeLoop(head);

    // Check if loop is removed
    if (detect(head) == NULL) {
        printf("Loop is removed\n");
    } else {
        printf("Loop is not removed\n");
    }

    printf("Updated List:\n");
    print(head);

    return 0;
}
