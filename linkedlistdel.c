#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *head=NULL;

void create()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *ptr;
    if(temp==NULL)
    {
        printf("\nInsufficient memory space");
    }
    printf("\nEnter data value of node");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    } else {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}

void display()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nEmpty list");
    } else {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("\n%d",ptr->info);
            ptr=ptr->next;
        }
    }
}

void del_front()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nEmpty list");
    } else {
        temp=head;
        head=temp->next;
        free(temp);
    }
}

void del_end()
{
    // temp - the last node, temp1 - the node before the last node
    struct node *temp,*temp1;
    if(head==NULL)
    {
        printf("\nEmpty list");
    } else if(head->next==NULL) {
        temp=head;
        free(head);
    } else {
        temp=head;
        while(temp->next!=NULL){
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        free(temp);
    }
}

void del_pos()
{
    struct node *temp,*temp1;
    int loc,i;
    printf("\nEnter position from which node has to be deleted");
    scanf("%d",&loc);
    temp=head;
    for(i=0;i<=loc;i++)
    {
        temp1=temp;
        temp=temp->next;
        if(temp==NULL)
        {
            printf("\nCannot be deleted");
        }
        temp1->next=temp->next;
        free(temp);
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
            del_front();
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
