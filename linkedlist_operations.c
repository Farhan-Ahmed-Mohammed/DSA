#include<stdio.h>
#include<stdlib.h>

struct Node
{
    
    int data;
   struct Node* next;

};

struct Node* create(int x)  //creation
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}

struct Node *insertAtHead(int x,struct Node* head)  //insertion
{
    struct Node *newNode=create(x);
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

struct Node* delete(struct Node* head,int x)
{
    if(head==NULL)
    {
        printf("The list is empty");
        return head;
    }

    if(head->data==x)
    {
        struct Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    struct Node* temp=head;
    while(temp->next!=NULL && temp->next->data!=x)
    {
        temp=temp->next;
    }

    if(temp->next==NULL)
    {
        printf("Node not found");
        return head;
    }

    struct Node* nodetodelete=temp->next;
    temp->next=temp->next->next;
    free(nodetodelete);
    return head;
   
    
}

void print( struct Node *head)   //trsaverseal
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
    printf("linked list :\n");
    print(head);
    head=delete(head,15);
    printf("After deleting :\n");
    print(head);
}

