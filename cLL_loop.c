#include<stdio.h>
#include<stdlib.h>

struct Node
{
    
    int data;
   struct Node* next;

};

struct Node *insertAtHead(int x,struct Node* head)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory not allocated");
        return head;
    }
     
    newNode->data=x;
  
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
    



struct Node* checkCircular(struct Node* head)
{
    struct Node* temp=head->next;
    if(temp!=NULL && temp->next!=head)
    {
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("It don't have loop");
    }

    else
    {
        printf("It has loop");
    }
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

int main()
{
    struct Node *head=NULL;
    head=insertAtHead(30,head);
    head=insertAtHead(25,head);
    head=insertAtHead(35,head);
    head=insertAtHead(15,head);
    print(head);
    head=checkCircular(head);
   
}

