#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtHead(int x, struct Node* head) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory not allocated");
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

void print(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when we reach the head again
}

struct Node* findMid(struct Node* head) {   //fast and slow pointer method
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    // Move fast pointer two steps and slow pointer one step
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;      // Move slow pointer one step 
        fast = fast->next->next; // Move fast pointer two steps 
    }

    return slow;
}

void divide(struct Node* head) {
    if(head==NULL)
    {
        return;
    }
    struct Node* mid = findMid(head);
    struct Node* temp=head;
    struct Node* head1=NULL;
   while(temp->next!=mid)
   {
        temp=temp->next;
   }
   head1=temp->next;
   temp->next=head;

   struct Node* temp2=head1;
    while(temp2->next!=head)
   {
        temp2=temp2->next;
   }
   temp2->next=head1;
     printf("After dividing first list:\n");
    print(head1);
     printf("After dividing 2nd list:\n");
     print(head);
    

}

int main() {
    struct Node* head = NULL;
    struct Node* head1 = NULL;
    head = insertAtHead(30, head);
    head = insertAtHead(25, head);
    head = insertAtHead(35, head);
    head = insertAtHead(15, head);
    head = insertAtHead(45, head);
    head = insertAtHead(50, head);
    
    print(head);
    divide(head);
}



