// all operations for singly linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *start2 = NULL;

// insertion at beginning
void insertbeg(int item)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nList full");
    }
    newnode->data = item;
    newnode->next = NULL;
    if(start == NULL)
    {
        start = newnode;
    } else {
        newnode->next = start;
        start = newnode;
    }

}

// insertion at end
void insertened(int item)
{
    struct node *newnode, *ptr;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("\nList full");
    }
    newnode->data = item;
    newnode->next = NULL;
    if(start == NULL)
    {
        start = newnode;
    } else {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = newnode;
    }

}

// insertion after spec node
void insertafter(int item)
{
struct node *newnode, *ptr;
int i,pos;
newnode = (struct node*)malloc(sizeof(struct node));
if(newnode == NULL)
{
    printf("\nMemory space not allocated");
}
printf("\nEnter position for new node to be inserted");
scanf("%d",&pos);
newnode->data = item;
newnode->next = NULL;

if(pos==0)
{
    newnode->next = start;
    start=newnode;
} else {
    ptr=start;
    for(i=0;i<pos-1;i++)
    {
        ptr = ptr->next;
        if(ptr==NULL)
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
struct node *newnode, *ptr, *preptr;
int loc;
newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = item;
newnode->next = NULL;

if(start == NULL)
{
    start = newnode;
} else {
    printf("\nEnter location before which you would like to insert");
    scanf("%d",&loc);
    ptr=start;

    while(ptr->data!=loc;)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    newnode->next=ptr;
    preptr->next=newnode;
}
}

// deletion at beginning
void beg_del()
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

// deletion at end
void last_del()
{
    struct node *ptr,*preptr;
    if(start == NULL)
    {
        printf("\nEmpty list");
    } else {
        ptr=start;
        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
   
}


// deletion of node after
void delafter()
{
    struct node *ptr,*ptr1;
    int loc,i;
    scanf("%d",&loc);
    ptr = start;
    for(i=0;i<loc;i++)
    {
        ptr1=ptr;
        ptr=ptr->next;

        if(ptr == NULL)
        {
            printf("\nThere are less than %d elements in this list",loc);
        }
    }
    ptr1->next=ptr->next;
    free(ptr);
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
        printf("\nEnter items which you would like to search?");
        scanf("%d",&item);
        while(ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("\nItem found at location %d",i+1);
                flag = 0;
            } else {
                flag = 1;
            }
            i++;
            ptr=ptr->next;
        }
        if(flag==1)
        {
            printf("\nItem not found");
        }
    }
}

//counting
void count()
{
    struct node *temp;
    temp = start;
    int count = 0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    printf("\nTotal number of counts is %d",count);
}

//for concat one
void create2()
{
    int num = 1;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *temp;

    while(num)
    {
        int s,y;
        printf("\nEnter integer");
        scanf("%d",&s);
        newnode->data = s;

        if(start2 == NULL)
        {
            newnode->next = NULL;
            start2 = newnode;
        } else {
          temp = start2;
          while(temp->next!=NULL)
          {
              temp=temp->next;
          }
          temp->next = newnode;
          newnode ->next = NULL;   
        }  
        printf("Do you want to create more nodes 1[yes] and 0[no]");
        scanf("%d",&num);
    }
}

// concatenation
void concat()
{
    struct node *ptr;
    if(start == NULL)
    {
        start = start2;
    }
    if(start2 == NULL)
    {
        start2 = start;
    }
    ptr=start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=start2;
}

//sorting
void sort()
{
    struct node *i, *j;
    int temp;
    for(i=start; i->next!=NULL; i=i->next){
        for(j=i->next; j!=NULL; j=j->next){
            if(i->data>j->data)
            {
                temp=i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

//reverse
void reverse()
{
    struct node *prev = NULL;
    struct node *current = item;
    struct node *next = NULL;

    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}



// displaying
void display()
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
    printf("\n1.Insertion at beginning\n2.Insertion at end\n3.Insertion after\n4.Deletion at beginning\n5.Deletion at end\n6.Deletion after\n7.search\n8.traverse\n9.exit\n10.insert before");
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
        case 10:
        printf("\nEnter data value");
        scanf("%d",&item);
        insertbefore(item);
        default:
        printf("\nWrong choice");
        break;
        
    }
}
    return 0;
}
