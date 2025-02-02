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

struct Node *insertAtHead2(int x,struct Node* head2)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory not allocated");
        return head2;
    }
     
    newNode->data=x;
    newNode->next=head2;
    head2=newNode;
    return head2;
    

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

void print2( struct Node *head2)
{
    struct Node* temp=head2;
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }

}

struct Node* intersect(struct Node* head,struct Node* head2)
{
    struct Node* temp1=head;
     struct Node* temp2=head2;
     while(temp1->data!=temp2->data)
     {
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==NULL)
        {
            temp1=head2;
        }

        if(temp2==NULL)
        {
            temp2=head;
        }
     }
     return temp1->data;

}

int main()
{
    struct Node *head=NULL;
    struct Node* head2=NULL;
    head=insertAtHead(30,head);
    head=insertAtHead(25,head);
    head=insertAtHead(35,head);
    head=insertAtHead(15,head);
    print(head);
    printf("List two :\n");
     head2=insertAtHead(31,head2);
    head2=insertAtHead(25,head2);
    head2=insertAtHead(10,head2);
    head2=insertAtHead(5,head2);
    print2(head2);
    printf("The point of intersection is :");
    struct Node* result=NULL;
    result=intersect(head,head2);
    printf("%d",result);
    
   
}

