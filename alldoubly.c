#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    struct node *prev;
    int data;
};
struct node *start = NULL;

void insert_end()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    printf("\nEnter data value for node");
    scanf("%d",&newnode->data);

    if(start == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        start = newnode;
    } else {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = newnode;
        newnode->prev = ptr;
        newnode->next = NULL;
    }
}

void insert_beg()
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("\nEnter node value");
    scanf("%d",&newnode->data);
    if(start == NULL)
    {
        start = newnode;
    } else {
        newnode->prev = NULL;
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
}

void insert_left()
{
    struct node *newnode,*temp;
    int i,loc;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("\nEnter node value");
    scanf("%d",&newnode->data);
    printf("\nEnter location");
    scanf("%d",&loc);

    temp=start;
    struct node *temp1;
    while(temp->data!=loc)
    {
        temp1=temp;
        temp=temp->next;
    }
    newnode->prev = temp1;
    newnode->next=temp;
    temp1->next=newnode;
    temp->prev = newnode;
}

void insert_right()
{
    struct node *newnode, *temp;
    int i,loc;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    printf("\nEnter  node value");
    scanf("%d",&newnode->data);
    printf("\nEnter value of node before of which new node is inserted to right of");
    scanf("%d",&loc);

    temp=start;
    while(temp->next!=loc)
    {
        temp=temp->next;
    }
    temp->next=newnode->next;
    temp->next = newnode;
    newnode->prev = temp;
    temp->next->prev = newnode;
}

void beg_del()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nEmpty list");
    } else if (start->next==NULL) {
        start = NULL;
        free(start);
    } else {
        ptr = start;
        start = start->next;
        start->prev;
        free(ptr);
    }
}

void end_del()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nEmpty list");
    } else if (start->next==NULL) {
        start = NULL;
        free(start);
    } else {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
    }
}

void spec_del()
{
    struct node *ptr, *temp;
    int val;
    printf("\nEnter value");
    scanf("%d",&val);
    temp = start;
    while(temp->data!=val)
    temp=temp->next;
    if(temp->next == NULL)
    {
        printf("\nCan't delete");
    } else if (temp->next->next == NULL) {
        temp->next = NULL;
    } else {
        ptr = temp->next;
        temp->next = ptr->next;
        ptr->next->prev = temp;
        free(ptr);
    }
}

void search()
{
    struct node *ptr;
    int item, i=0, flag;
    ptr = start;
    while(ptr==NULL)
    {
        printf("\nEmpty list");
    } else {
        printf("\nEnter item to search for");
        scanf("%d",&item);
        while(ptr!=NULL)
        {
            if(ptr->data==item) {
                printf("item found at %d",i+1);
                flag = 0;
            } else {
                flag =1;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag ==1)
        {
            printf("\nItem not found");
        }
    }
}

int traverse()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nEmpty list");
    } else {
    ptr = start;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    }
}

int main()
{   
    int ch;
    int item;
    while(1)
    {
    printf("\n1.Insertion at beginning\n2.Insertion at end\n3.Insertion after\n4.Deletion at beginning\n5.Deletion at end\n6.Deletion after\n7.search\n8.traverse\n9.exit");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
        printf("\nEnter data value");
        scanf("%d",&item);
        insertbeg(item);
        break;
        case 2: 
        printf("\nEnter data value");
        scanf("%d",&item);
        insertened(item);
        break;
        case 3:
        printf("\nEnter data value");
        scanf("%d",&item); 
        insertafter(item);
        break;
        case 4: 
        beg_del();
        break;
        case 5: 
        last_del();
        break;
        case 6:
        delafter();
        break;
        case 7:
        search();
        break;
        case 8:
        traverse();
        break;
        case 9:
        exit(0);
        break;
        default:
        printf("\nWrong choice");
        break;
        
    }
}
    return 0;
}
