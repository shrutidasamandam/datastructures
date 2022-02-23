#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int data;
};
struct node *start = NULL;

void beg_insert(int item)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    if(newnode == NULL)
    {
        printf("\nOverflow");
    } else {
        newnode->data = item;
        if(start == NULL)
        {
            start = newnode;
            newnode->next = start;
        } else {
            ptr = start;
            while(ptr->next!=start)
            ptr=ptr->next;
            newnode->next = start;
            ptr->next=newnode;
            start = newnode;

        }
    }
}

void end_insert(struct node *newnode, struct node *ptr, int item)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nOverflow");
    } else {
        newnode->data = item;
        if(start == NULL)
        {
            start = newnode;
            newnode->next = start;
        } else {
            ptr = start;
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=start;
        }
    }
}

void beg_del()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nUnderflow");
    } else if (start->next == start)
    {
        start = NULL;
        free(start);
    } else {
        ptr = start;
        while(ptr->next!=start)
        ptr=ptr->next;
        ptr->next = start->next;
        free(start);
        start = ptr->next;
    }
}

void end_del()
{
    struct node *preptr, *ptr;
    if(start == NULL)
    {
        printf("\nUnderflow");
    } else if (start->next == start)
    {
        start = NULL;
        free(start);
    } else {
        ptr = start;
        while(ptr->next!=start)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
    }
}
