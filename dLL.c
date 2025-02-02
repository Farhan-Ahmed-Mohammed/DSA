#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node* lptr;
    struct Node* rptr;
};

struct Node* doubleInsert(struct Node *L,struct Node *R,struct Node *M,int x)
{
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    if(new==NULL)
    {
        printf("Empty list");
        return L;
    }

    new->info=x;
    new->lptr=L;
    new->rptr=R;

    if(R==NULL)
    {
        new->lptr=new->rptr=NULL;
        return new;
    }

    if(L==M)        // inserting at left size M is current node
    {
        new->lptr=NULL;
        new->rptr=M;
        M->lptr=new;
        return new;
    }

    //inserting in the middle
    new->lptr=M->lptr;
    new->rptr=M;
    M->lptr->rptr=new;
    M->lptr=new;

    return L;
}

void print(struct Node *L)
{
    struct Node* temp=L;
    while(temp!=NULL)
    {
        printf("%d\n",temp->info);
        temp=temp->rptr;
    }

}

int main()
{
    struct Node* L=NULL;
    struct Node* R=NULL;
    int value;
    value=10;
    L=R=doubleInsert(L,R,L,value);
    value=20;
    L=doubleInsert(L,R,L,value);
    value=15;
    L=doubleInsert(L,R,R,value);
    print(L);
}