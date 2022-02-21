#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert_left()
{
    int loc;
    struct node *temp;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter node value");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;

    printf("\nEnter value of node before which new node is inserted to left of");
    scanf("%d",&loc);
    temp = head;
    struct node *temp1;
    while(temp->data!=loc)
    {
        temp1 = temp;
        temp = temp->next;
    }
    newnode->prev=temp1;
    newnode->next=temp;
    temp1->next = newnode;
    temp->prev = newnode;
}

void del_spec()
{
    struct node *ptr, *temp;
    int val;
    printf("\nEnter value");
    scanf("%d",&val);
    temp=head;

    while(temp->data!=val)
        temp=temp->next;
    if(temp->next==NULL)
    {
        printf("\nCan't delete");
    } else if(temp->next->next==NULL)
    {
        temp->next=NULL;
    } else {
        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
    }
}

void create()
{
    int num = 1;
    while(num)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        struct node *temp;
        printf("\nEnter new node value");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;

        if(head==NULL)
        {
            head=newnode;
        } else {
            temp = head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
        printf("Do you want to create more nodes 1[yes] and 0[no]");
        scanf("%d",&num);
    }
}

void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nEmpty list");
    } else {
        temp = head;
        while(temp!=NULL)
        {
            printf("\n%d",temp->data);
            temp = temp->next;
        }
    }
}

int main()
{   
    int ch;
    while(1)
    {
    printf("\n1.Create\n2.Insert a new node to the left of the node\n3.Delete the node based on a specific value\n4.Display\n5.Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: create();
        break;
        case 2: insert_left();
        break;
        case 3: del_spec();
        break;
        case 4: display();
        break;
        default: exit(0);
        
    }
}
    return 0;
}
