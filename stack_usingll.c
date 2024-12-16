#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head=NULL;

struct Node* create()
{
    struct Node* temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    return temp;
}

void push(int element)
{
    struct Node* temp=create();
    if(temp==NULL)
    {
        printf("Memory Not allocated");
        return;
    }

    temp->data=element;
    temp->next=head;
    head=temp;
    printf(" %d is pushed into the stack\n",element);
}

int pop()
{
   
    if(head==NULL)
    {
        printf("Under flow"); 
        return -1;
    }
    struct Node* temp=head;       //storing element that is to be deleted in temp
    int poppedElement=head->data;
    head=head->next;
    free(temp);                 //deleting the element
    printf(" %d is popped form stack\n",poppedElement);
    return poppedElement;

}

void print()
{
    struct Node* temp=head;
    if(temp==NULL)
    {
        printf("The stack is empty");
    }

    while(temp!=NULL)
    {
        printf(" %d ",temp->data);
        temp=temp->next;
    }

}

int main()
{
    push(5);
    push(10);
    push(15);
    push(20);
    push(25);
    printf("\nStack elements befere deleting :\n");
    print();
    printf("\nStack elements after deleting :\n");
    pop();
    print();

}