#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* create(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=x;
    temp->next=temp;
    return temp;
}

struct Node* insertAtTop(struct Node* head,int x)
{
    struct Node* newNode=create(x);     // it is the new node which we insert
    if(newNode==NULL)
    {
        printf("Memory not allocated");
        return head;
    }
    if (head == NULL) {
        return newNode;  // If the list is empty, new node is the only node and points to itself
    }

    struct Node* temp=head;// it moves till last and such that newnode can come to its correct place
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    newNode->next=head;  // its the last node so it should point to head
    temp->next=newNode;  // its last second node so it points to newNode
    return newNode;

}

struct Node* delete(struct Node* head,int x)
{
    if(head==NULL)
    {
        printf("The list is empty ");
        return head;
    }
    if (head->data == x)
    {
        // If there's only one node in the list
        if (head->next == head)
        {
            free(head);
            return NULL;  // List becomes empty
        }

        // Traverse to the last node
        struct Node* temp = head;  
        while (temp->next != head)
        {
            temp = temp->next;
        }

        // Last node's next should point to the new head
        temp->next = head->next;
        struct Node* nodeToDelete = head;
        head = head->next;  // Move head to the next node
        free(nodeToDelete);
        return head;
    }

    // if(head->data==x)
    // {
    //     struct Node* temp=head;  // store head in temp so that it dont get lost
    //     head=head->next;        // move head farward
    //     free(head);
    //     return head;
    // }

    struct Node* temp=head;
    while(temp->next!=NULL && temp->next->data!=x)
    {
        temp=temp->next;
    }

    if(temp->next==NULL)
    {
        printf("Element is no there in the list ");
        return head;
    }
    struct Node* nodeToDelete=temp->next;
    temp->next=temp->next->next;
    free(nodeToDelete);
    return head;
}

void print(struct Node* head)
{
    struct Node* temp=head;
    if(head==NULL)
    {
        printf("The list is empty");
    }
    
    do
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }while(temp!=head);
    
}

int main()
{
    struct Node* head=NULL;
    head=insertAtTop(head,5);
    head=insertAtTop(head,10);
    head=insertAtTop(head,15);
    head=insertAtTop(head,20);
    head=delete(head,20);
    print(head);
}