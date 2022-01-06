#include <stdlib.h>
#include <stdio.h>

void create();
void display();
void delete_pos();
void delete_front();
void delete_end();

struct node
{
    int info;
    struct node *next;
};
struct node *head = NULL;
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
            delete_end();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            delete_pos();
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
void create()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space");
        exit(0);
    }
    printf("\nEnter the data value for the node:");
    scanf("%d", &temp->info);
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void display()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty:");
        return;
    }
    else
    {
        ptr = head;
        printf("\nThe List elements are:");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->info);
            ptr = ptr->next;
        }
    }
}
void delete_front() {
    struct node *temp;
    if(head==NULL){
        printf("\nEmpty List");
    } else {
        temp=head;
        head=temp->next;
        free(temp);
    }
}
void delete_end()
{
struct node *temp,*temp1;
if(head==NULL)
{
printf("\n the list is empty");
}
else if(head->next==NULL)
{
temp=head;
free(head);
printf("\n the node is deleted");
}
else
{
temp=head;
while(temp->next!=NULL)
{
temp1=temp;
temp=temp->next;
}
temp1->next=NULL;
free(temp);
printf("\n node is deleted from the last");
}
}


void delete_pos()
{
struct node *temp,*temp1;
int loc,i;
printf("\n enter the position from which the node has to be deleted:");
scanf("%d",&loc);
temp=head;
for(i=0;i<=loc;i++)
{
temp1=temp;
temp=temp->next;
if(temp==NULL)
{
printf("\n cant delete!!");
return;
}
temp1->next=temp->next;
free(temp);
}
}
