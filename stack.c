#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
int stack[SIZE], top = -1, value, choice;


void push(){
    if(top==SIZE-1)
    {
        printf("\nStack is full");
    } else {
        printf("\nEnter the value to be insert: ");
        scanf("%d",&value);
        top++;
        stack[top]=value;
        printf("\nInsertion valid");
    }
}

void pop(){
    if(top==-1)
    {
        printf("\nStack is Empty");
    } else {
        printf("\nDeleted:%d",stack[top]);
        top--;
    }
}

void display(){
    if(top==-1){
        printf("\nStack is empty");
    } else {
        int i;
        printf("\nStack elements are:");
        for(i=top;i>=0;i--){
            printf("\n%d",stack[i]);
        }
    }
}

int main(){
    while(1){
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.display");
        printf("\n4.exit");
        printf("\nenter your choice:");    
        scanf("%d",&choice);
        switch(choice){
            case 1: 
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default: printf("\nWrong selection");

        }
        
        }
}