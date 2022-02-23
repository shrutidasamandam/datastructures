// all operations for doubly linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start = NULL;

// insertion at beginning
void insertbeg(int item)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(start == NULL)
    {
        newnode->next = NULL;
        newnode->prev = NULL;
        newnode->data = item;
        start = newnode;
    } else {
        newnode->data = item;
        newnode->prev = NULL;
        newnode->next = start;
        start -> prev = newnode;
        start = newnode;
    }
}

// insertion at end
void insertened(int item)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    newnode->data = item;

    if(start==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        start = newnode;
    } else {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next =newnode;
        newnode->prev = ptr;
        newnode->next = NULL;
    }
}

// insertion after spec node
void insertafter(int item)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    int i,loc;
    
    printf("\nEnter location");
    scanf("%d",&loc);

    ptr = start;
    for(i=0;i<loc-1;i++)
    {
        ptr=ptr->next;
        if(ptr == NULL)
        {
            printf("\nCannot insert");
        }
    }
    newnode->data = item;
    newnode->next = ptr->next;
    newnode->prev = ptr;
    ptr->next = newnode;
    ptr->next->prev = newnode;

}

void insertbefore(int item)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *ptr,*temp1;
    int loc;

    printf("\nEnter location");
    scanf("%d",&loc);

    ptr = start;
    while(ptr->data!=loc)
    {
        temp1=ptr;
        ptr=ptr->next;
    }
    newnode->data = item;
    newnode->prev=temp1;
    newnode->next=ptr;
    temp1->next = newnode;
    ptr->prev = newnode;
}

// deletion at beginning
void beg_del()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nUnderflow");
    } else if (start->next == NULL){
        start = NULL;
        free(start);
    } else {
        ptr = start;
        start = start->next;
        start->prev = NULL;
        free(ptr);
    }
}

// deletion at end
void last_del()
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nUnderflow");
    } else if (start->next == NULL) {
        start = NULL;
        free(start);
    } else {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
    }
}

// deletion of node after
void delafter()
{
    struct node *ptr,*temp;
    int loc;
    printf("\nEnter location");
    scanf("%d",&loc);

    ptr = start;
    while(ptr->data!=loc)
        ptr=ptr->next;
    if(ptr->next == NULL)
    {
        printf("\nCannot delete");
    } else if (ptr->next->next == NULL) {
        ptr->next=NULL;
    }
    temp=ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
}

// searching 
void search()
{
    struct node *ptr;
    int item, i=0, flag;
    ptr = start;

    if(ptr == NULL)
    {
        printf("\nEmpty list");
    } else {
        printf("\nEnter item which you are searching for");
        scanf("%d",&item);
        while(ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("\nItem found at location %d",i+1);
                flag = 0;
                break;
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

// displaying
void traverse()
{
    struct node *ptr;
    if(start == NULL) {
        printf("\nEmpty list");
    } else {
        ptr = start;
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->data);
            ptr = ptr->next;
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
