/*WAP to implement Stack & Queues using Linked List Representation*/

#include <stdio.h>
#include <stdlib.h>

struct qnode {
    struct qnode *next;
    int qdata;
};
struct qnode *qhead;

void enqueue()
{
    struct qnode *temp = (struct qnode*)malloc(sizeof(struct qnode));
    struct qnode *ptr;
    if(temp == NULL)
    {
        printf("\nInsufficient memory");
    }
    printf("\nEnter data for node");
    scanf("%d",&temp->qdata);
    if(qhead==NULL)
    {
        qhead = temp;
    } else {
        ptr = qhead;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void dequeue()
{
    struct qnode*temp;
    if(qhead==NULL)
    {
        printf("\nEmpty list");
    } else {
        temp = qhead;
        qhead = temp->next;
        free(temp);
    }
}


void display2()
{
    struct qnode *temp;
    temp = qhead;
    if(qhead==NULL)
    {
        printf("\nEmpty list");
    } else {
        while(temp!=NULL)
        {
            printf("\n%d",temp->qdata);
            temp = temp->next;
        }
    }
}

struct node {
    struct node *next;
    int data;
};
struct node *head;

void push()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("\nInsufficient memory");
    }
    printf("\nEnter data ");
    scanf("%d",&temp->data);
    temp->next = NULL;
    if(head==NULL)
    {
        head = temp;
    } else {
        temp -> next = head;
        head = temp;
    }
}

void pop()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nEmpty list");
    } else {
        temp = head;
        head = temp->next;
        free(temp);
    }
}


void display()
{
    struct node *temp;
    temp = head;
    if(head==NULL)
    {
        printf("\nEmpty list");
    } else {
        while(temp!=NULL)
        {
            printf("\n%d",temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int intchoice, choice;
    while(1) {
        printf("\n----menu----");
        printf("\n--stack implementation--");
        printf("\n1.push \n2.pop \n3.display \n7.exit");
        printf("\n--queue implementation--");
        printf("\n4.enqueue \n5.dequeue \n6.display \n7.exit");
        printf("\nenter your choice ");
        scanf("%d",&choice);
        switch(choice){
            case 1: push();
                break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: enqueue();
                    break;
            case 5: dequeue();
                    break;
            case 6: display2();
                    break;
            case 7: exit(0);
            default: printf("\nentered wrong choice");
                    
        }
        
        }
    return 0;
}
