#include<stdio.h>

#define SIZE 8

int front = -1, rear = -1;
int q[SIZE];

int isFull()
{
    if(((rear+1)%SIZE)==front)
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if(front==-1)
    {
        return 1;
    }
    return 0;
}
void enqueue(int a)
{
    if(isFull())
    {
        printf("You cant enqueue because queue is full.");
    }
    else
    {
        if (front == -1)
        front = 0;
        rear=((rear+1)%SIZE);
        q[rear]=a;
    }
}
void dequeue()
{
   
    if(isEmpty())
    {
        printf("There arent any elements to dequeue.");
    }
    else
    {
        printf("The element dequeued is %d", q[front]);
        if (front == rear)
        {
           front = -1;
           rear = -1;
        }  
        else
          front=((front+1)%SIZE);
    }
}

int main()
{
    int c = 0;
    while(c!=3)
    {
    printf("1.Enqueue \n2.Dequeue\n3.Exit\n");
    scanf("%d", &c);
    switch(c)
    {
        case 1:
        {
            int e;
            printf("Enter the element to be enqueued: \n");
            scanf("%d", &e);
            enqueue(e);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            break;
        }
        default:
        {
            printf("Invalid option.\n");
        }
    }
   }
}
