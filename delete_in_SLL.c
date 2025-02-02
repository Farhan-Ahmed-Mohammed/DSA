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
    newNode->next=head;
    head=newNode;
    return head;
    

}

struct Node* delete(int deleteNode,struct Node* head)
{  

    if(head==NULL)
    {
        printf("Empty list");
        return head;
    }

    if(head->data==deleteNode)
    {
        head=head->next;
        return head;

    }
    struct Node* temp=head;
     struct Node* pre=NULL;

    while(temp!=NULL && temp->data!=deleteNode)
    {  
        pre=temp;
        temp=temp->next;
        
    }

    if(temp==NULL)
    {
        printf("Element Not found");
        return head;
    }
    pre->next=temp->next;
    temp->next=NULL;
    free(temp);
    return head;



}

void print( struct Node *head)
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

}

int main()
{
    struct Node *head=NULL;
    head=insertAtHead(30,head);
    head=insertAtHead(25,head);
    head=insertAtHead(35,head);
    head=insertAtHead(15,head);
    printf("Before deleting :\n");
    print(head);
     printf("After deleting :\n");
     head=delete(35,head);
     print(head);
}

