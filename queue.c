#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int rear = 0;
int front = 0;
int queue[SIZE];

void insert(){
    if(rear==SIZE){
        printf("\n queue is overflowing");
    } else {
        if (front==-1)
            front = 0;
            printf("\n insert the element in the queue ");
            scanf("%d", &queue[rear]);
            rear++;
    }
}

void delete(){
    if(front==rear)
    printf("\n queue is underflowing");
    else {
        printf("\n deleted element is: %d", queue[front]);
        front++;
    }
}

void display(){
    int i;
    if(rear==0 && front==0)
        printf("\n queue is empty");
    else {
        printf("\n queue is:");
        for(i=front;i<rear;i++){
            printf("%d",queue[i]);
            printf("\n");
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("\n 1. insert");
        printf("\n 2. delete");
        printf("\n 3. display");
        printf("\n 4. exit");
        printf("\n enter choice ");
        scanf("%d", &choice);
        switch(choice){
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(1);
            default: printf("\n wrong option");
        }
    }
}
