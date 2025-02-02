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
// void findMid(struct Node *head)
// {
//     struct Node* temp=head;
//     struct Node* temp2=head;
//     int count=0;
//     while(temp!=NULL)
//     {
//         temp=temp->next;
//         count++;
//     }

//     int mid=(count/2)+1;

//     int count2=0;
//     while(count2!=mid-1)
//     {
//         temp2=temp2->next;
//         count2++;
//     }
//     printf("%d",temp2->data);
// }

void findMid(struct Node* head) {   //fast and slow pointer method
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    // Move fast pointer two steps and slow pointer one step
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;      // Move slow pointer one step here slow is middle element 
        fast = fast->next->next; // Move fast pointer two steps fast is last element moves 2 steps
    }

    printf("The middle element is: %d\n", slow->data);
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
    printf("The middle element is :");
   findMid(head);
    
}

