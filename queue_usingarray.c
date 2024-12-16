#include<stdio.h>
int f=-1;
int r=-1;
int n=4;

void qinsert(int q[],int element)
{
    if(r>=n)
    {
        printf("Over flow");
    }

    else
    {
        r=r+1;
        q[r]=element;
        
    }

    if(f==-1)
    {
        f=0;
    }
}

void qdelete(int q[])
{
    if(f==-1)
    {
        printf("Under flow");
    }

    if(f==r)
    {
        f=-1;
        r=-1;
    }
    f=f+1;
}

int main()
{
    int q[100];
    qinsert(q,5);
    qinsert(q,10);
    qinsert(q,15);
    qinsert(q,20);
    printf("\nThe queue before deleting :\n");
    for(int i=f;i<=r;i++)
    {
        printf("%d ",q[i]);
    }
    printf("\nThe queue after deleting :\n");
    qdelete(q);
    for(int i=f;i<=r;i++)
    {
        printf("%d ",q[i]);
    }
}