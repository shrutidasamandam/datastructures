/*WAP to implement Stack & Queues using Linked List Representation*/

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
void enqueue();
void dequeue();
void display2();

//stack
struct node{
    int data; 
    struct node *next;
};
struct node *head;

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

void push ()
{
    int data;
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("\nstack full");
    } else {
        printf("\nenter value to be inserted: ");
        scanf("%d",&data);
        if(head==NULL)
        {
            new_node->data=data;
            new_node->next=NULL;
            head=new_node;
        } else {
            new_node->data=data;
            new_node->next=head;
            head=new_node;
        }
    }
}

void pop()
{
    int item;
    struct node *new_node;
    if(head==NULL)
    {
        printf("\nempty stack");
    } else {
        item=head->data;
        new_node=head;
        head=head->next;
        free(new_node);
    }
}

void display()
{
    int i;
    struct node* new_node;
    new_node=head;
    if(new_node==NULL)
    {
        printf("\nempty stack");
    } else {
        while(new_node!=NULL)
        {
            printf("\n%d",new_node->data);
            new_node=new_node->next;
        }
    }

}
//queue
struct qnode{
    int qdata;
    struct qnode *qnext;
};
struct qnode *qfront;
struct qnode *qrear;

void enqueue()
{
    struct qnode* ptr;
    int item;
    
    ptr=(struct qnode *)malloc(sizeof(struct qnode));
    if(ptr==NULL)
    {
        printf("\nqueue overflow");
    } else {
        printf("\nenter value");
        scanf("%d",&item);
        ptr->qdata=item;
        if(qfront==NULL)
        {
            qfront=ptr;
            qrear=ptr;
            qfront->qnext=NULL;
            qrear->qnext=NULL;
        } else {
            qrear->qnext=ptr;
            qrear=ptr;
            qrear->qnext=NULL;
        }
    }
}

void dequeue()
{
    struct qnode *ptr;
    if(qfront==NULL)
    {
        printf("\nqueue empty");
    } else {
        ptr=qfront;
        qfront=qfront->qnext;
        free(ptr);
    }
}

void display2()
{
    struct qnode *ptr;
    ptr=qfront;
    if(qfront==NULL)
    {
        printf("\nqueue empty");
    } else {
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->qdata);
            ptr=ptr->qnext;
        }
    }
}
