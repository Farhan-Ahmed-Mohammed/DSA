#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // for using bool in C

struct Node {
    int data;
    struct Node* next;
};


struct Node* insertAtHead(int x, struct Node* head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated\n");
        return head;
    }

    newNode->data = x;
    newNode->next = head;
    head = newNode;
    return head;
}


bool checkPalindrom(int arr[], int n) {
    int s = 0;
    int e = n - 1;

    while (s < e) {
        if (arr[s] == arr[e]) {
            //return false;  
        s++;
        e--;
    }
    else{
        return false;
    }
    return true;  // It's a palindrome
}
}


bool isPalindrom(struct Node* head) {
    int arr[100];  
    int i = 0;

   
    struct Node* temp = head;
    while (temp != NULL) {
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }

    
    return checkPalindrom(arr, i);
}

// Print the linked list
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    head = insertAtHead(1, head);
    head = insertAtHead(2, head);
    head = insertAtHead(3, head);
    head = insertAtHead(2, head);
    head = insertAtHead(1, head);

    print(head);

    // Check if the linked list is a palindrome
    if (isPalindrom(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    return 0;
}
