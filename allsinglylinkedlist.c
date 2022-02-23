#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *start2 = NULL;

void insertbeg(int item)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nNot enough memory");
    } 
    newnode->next = NULL;
    newnode->data = item;
    if(start == NULL)
    {
        start=newnode;
    } else {
        newnode->next = start;
        start = newnode;
    }
}

void insertend(int item)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    if(newnode == NULL)
    {
        printf("\nNot enough memory");
    }
    newnode->data = item;
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
    } else {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}

void insertafter(int item)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    int i,pos;
    if(newnode == NULL)
    {
        printf("\nFull");
    }
    newnode->next = NULL;
    newnode->data = item;

    if(pos==0)
    {
        newnode->next = start;
        start = newnode;
    } else {
        ptr = start;
        for(i=0; i<pos-1; i++)
        {
            ptr=ptr->next;
            if(ptr == NULL)
            {
                printf("\nPosition not found");
            }
        }
        newnode->next = ptr->next;
        ptr->next = newnode;

    }
}

void insertbefore(int item)
{
    struct node *preptr, *ptr;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    int loc;
    newnode->data = item;
    newnode->next = NULL;

    if(start == NULL)
    {
        start = newnode;
    } else {
        printf("\nEnter location to insert  before");
        scanf("%d",&loc);
        ptr = start;

        while(ptr->data!=loc)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        newnode->next = ptr;
        preptr->next = newnode;
    }
}

void display()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nEmpty list");
    } else {
        ptr = start;
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->data);
            ptr=ptr->next;
        }
    }
}

void deletebeg()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nEmpty list");
    } else {
        ptr = start;
        start = ptr->next;
        free(ptr);
    }
}

void deleteend()
{
    struct node *preptr, *ptr;
    if(start == NULL)
    {
        printf("\nEmpty list");
    } else {
        ptr = start;
        while(ptr->next!=NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
}

void deleteafter()
{
    struct node *preptr, *ptr;
    int i,loc;
    if(start == NULL)
    {
        printf("\nEmpty list");
    } else {
    ptr = start;
    for(i=0; i<loc; i++)
    {
        preptr = ptr;
        ptr=ptr->next;
        if(ptr == NULL)
        {
            printf("\nCannot find location");
        }
    }
    preptr->next = ptr->next;
    free(ptr);
    }
}

void search()
{
    int i,item,flag;
    struct node *ptr;
    ptr = start;

    if(ptr == NULL)
    {
        printf("\nEmpty");
    } else {
        printf("\nEnter item to find");
        scanf("%d",&item);

        while(ptr!=NULL)
        {
            if(ptr->data==item)
            {
                printf("\nItem found at %d",i+1);
                flag = 0;
            } else {
                flag = 1;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag == 1)
        {
            printf("\nItem not found");
        }
    }
}

void count()
{
    int count = 0;
    struct node *temp;
    temp = start;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("\ntotal number of nodes is %d",count);
}

void concat()
{
    struct node *ptr;
    if(start == NULL){
    start = start2;
    }
    if(start2 == NULL){
    start2 = start;
    }
    ptr = start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next = start;
}

void reverse()
{
    struct node *current = item;
    struct node *next = NULL;
    struct node *prev = NULL;

    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}

void sort()
{
    struct node *i,*j;
    int temp;
    for(i=start; i->next!=NULL; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
        {
            if(i->info>j->info)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void create2()
{
    struct node *temp;
    int s,y;
    do
    {
       struct node *newnode = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter integer: ");
        scanf("%d",newnode->data);
        newnode->next = NULL;

        if(start2 == NULL)
        {
            start2 = newnode;
        } else {
            temp = start2;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next = newnode;
        } 
        printf("\nDo you want to continue adding 0[no] or 1[yes]");
        scanf("%d",y);
    }while(y!=0);
}
