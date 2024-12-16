#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Queue
{
    struct Node* f;
    struct Node* r;
};

struct Queue q;   

void initQueue()
{
    q.f=q.r=NULL;
}

void qinsert(int element)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=element;
    newNode->next=NULL;

    if(q.r==NULL)
    {
         q.r=q.f=newNode;
         printf("%d is inserted in queue\n",element);
         return;
    }

    q.r->next=newNode;
    q.r=newNode;
    printf("%d is inserted in queue\n",element);
}

void qdelete()
{
    if(q.f==NULL)
    {
        printf("Under flow : The queue is empty");
    }

    struct Node* temp=q.f;
    q.f=q.f->next;
    printf("%d is deleted form the queue :",temp->data);

    if(q.f==NULL)
    {
        q.r=NULL;
    }
    free(temp);
}

void print() {
    if (q.f == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q.f;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    initQueue();
    qinsert(5);
    qinsert(6);
    qinsert(7);
    qinsert(8);
    qinsert(9);
    printf("\nThe queue before deleting elements :");
    print();
    qdelete();
    printf("\nThe queue after deleting elements :");
    print();


}

