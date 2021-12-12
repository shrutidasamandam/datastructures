#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int front = -1, rear =-1, queue[MAX], item;

void enqueue(){
    if(front==(rear+1)%MAX){
        printf("\nQueue is full");
    } else {
        printf("\nEnter element ");
        scanf("%d",&item);
        rear=(rear+1)%MAX;
        queue[rear]=item;
        if(front==-1){
            front=0;
        }
    }
}

void denqueue(){
    if(front==-1&rear==-1){
        printf("\nQueue is empty");
    } else {
        item = queue[front];
        if (front==rear)
        {
            front=-1;
            rear=-1;
        } else {
            front=(front+1)%MAX;
        }
    }
    }

void display(){
    int i;
    printf("\nQueue contents are: ");
    for(i=front;i!=rear;i=(i+1)%MAX)
    {
        printf("\n%d",queue[i]);        
    }
     printf("\n%d",queue[i]);        
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.display");
        printf("\n4.exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            enqueue();
            break;
            case 2:
            denqueue();
            break;
            case 3: 
            display();
            break;
            case 4:
            exit(1);
            default: printf("\nInvalid choice");
        }
    }
}