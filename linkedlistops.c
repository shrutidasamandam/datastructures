#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *start2 = NULL;
struct node *start = NULL;

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
    ptr = start;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=start2;
}

void sort()
{
    struct node *i,*j;
    int temp;
    for(i=start; i->next!=NULL ; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
        {
            if(i->data>j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverse()
{
    struct node *prev = NULL;
    struct node *current = start;
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

void create()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    if(temp == NULL)
    {
        printf("\nOut of memory space");
    }
    printf("\nEnter data value for node");
    scanf("%d",&temp->data);
    temp->next = NULL;
    if(start == NULL)
    {
        start = temp;
    } else {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = temp;
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
            ptr = ptr->next;
        }
    }
}

int main()
{
    int choice;
    while (1)
    {

        printf("\n----MENU----");
        printf("\n 1.Create");
        printf("\n 2.Display");
        printf("\n 3.Reverse");
        printf("\n 4.Sort");
        printf("\n 5.Concat");
        printf("\n 6.Exit");
        printf("\n Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            reverse();
            display();
            break;
        case 4:
            sort();
            display();
            break;
        case 5:
            create2();
            concat();
            display();
            break;
        case 6:
            exit(0);
            break;

        default:
            printf("\nWrong Choice:");
            break;
        }
    }
    return 0;
}
