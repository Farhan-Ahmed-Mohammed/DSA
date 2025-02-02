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
struct Node* findEndN(struct Node* head,int n)
{
    if(head==NULL)
    {
        printf("Empty list");
        return head;
    }
    struct Node* first=head;
    struct Node* second=head;

    for(int i=0;i<n;i++)
    {
        if(first==NULL)
        {
            printf("The list has less than n elements");
            return NULL;
        }
        first=first->next;
    }

    while(first!=NULL)
    {
        first=first->next;
        second=second->next;
    }
    return second;
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
    print(head);
    printf("The n th element form last is :\n");
    struct Node* result=findEndN(head,2);
    printf("%d",result->data);
   
    
}

