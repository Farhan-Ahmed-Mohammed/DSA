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

struct Node* reverse(struct Node* head)
{
    if(head==NULL)
    {
        printf("The list is empty");
        return head;
    }
    struct Node* current=head;
    struct Node* pre=NULL;
    struct Node* farward=NULL;

    while(current!=NULL)
    {
        farward=current->next; //store current next address before changing it other wise it gets lost
        current->next=pre;    //move currrent to back
        pre=current;     //move pre farward
        current=farward; //move current farward
    }
    
    return pre;
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
    printf("After reversing :\n");
    head=reverse(head);
    print(head);
}

