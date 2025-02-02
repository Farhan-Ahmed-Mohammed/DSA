#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* pre;
    struct Node* next;
};


struct Node* insertAtStart(struct Node* head, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->pre = NULL;
    temp->next = head;

    if (head != NULL) {
        head->pre = temp;
    }
    
    return temp; // The new node becomes the new head
}


struct Node* insertAtEnd(struct Node* tail, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->pre = tail;

    if (tail != NULL) {
        tail->next = temp;
    }

    return temp; // The new node becomes the new tail
}


void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    head = insertAtStart(head, 10);
    tail = head;                   // at first node both head and tail should point to same list
    head = insertAtStart(head, 11);
    tail = insertAtEnd(tail, 12);
    print(head);

    return 0;
}