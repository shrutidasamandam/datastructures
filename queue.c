#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int rear = 0, front = 0, queue[MAX];

void insert()
{
    if(rear == MAX){
        printf("\nqueue is overflowing");
    } else {
        if(front==-1)
        front=0;
        printf("\ninsert element in queue");
        scanf("%d",&queue[rear]);
        rear++;
    }
}

void delete()
{
    if(front==rear){
        printf("\nqueue underflow");
    } else {
        printf("\ndeleted element is: %d",queue[front]);
        front++;
    }
}

void display(){
    int i;
    if(rear==0||front==rear){
        printf("\nqueue is empty");
    } else {
        printf("\nqueue is: ");
        for(i=front;i<rear;i++){
            printf("\n%d",queue[i]);
        }
    }
}

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.display");
        printf("\n4.exit");
        printf("\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);
            default: printf("\nInvalid Choice");
        }

    }
}