#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *start = NULL;

void create()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
    {
        printf("\nInsufficient memory space");
    }
    printf("\nEnter data value for node");
    scanf("%d",&temp->data);
    temp->next = NULL;
    if(start==NULL)
    {
        start = temp;
    } else {
        temp->next=start;
        start=temp;
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

void del_pos()
{
    struct node *temp, *temp1;
    int loc,i;
    printf("\nEnter position which you would like to delete");
    scanf("%d",&loc);
    temp = start;
    for(i=0;i<loc;i++)
    {
        temp1 = temp;
        temp = temp->next;
        if(temp == NULL)
        {
            printf("\nPosition not found");
        }
        temp1->next = temp->next;
        free(temp);
    }
}

void del_end()
{
    struct node *temp, *temp1;
    if(start == NULL)
    {
        printf("\nEmpty list");
    } else if (start->next==NULL) {
        temp = start;
        free(start);
    } else if(start->next!=NULL) {
        temp = start;
        while(temp->next!=NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        free(temp);
    }
}

void del_beg()
{
    struct node *ptr;
    if(start==NULL)
    {
        printf("\nEmpty list");
    } else {
        ptr = start;
        start = ptr->next;
        free(ptr);
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
        printf("\n 3.Delete at the end");
        printf("\n 4.Delete at the front");
        printf("\n 5.Delete at the specified position");      
        printf("\n 6.Exit");
        printf("\n Enter your choice:\t");
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
            del_end();
            break;
        case 4:
            del_beg();
            break;
        case 5:
            del_pos();
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
