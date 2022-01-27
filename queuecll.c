//Implement a queue using a circular linked list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data; 
    struct node *next;
};
struct node *head = NULL;

void insert(int item);
int delete();
void display();
int isEmpty();

int main()
{
        int choice,item;
        while(1)
        {
                printf("\n1.Insert");
                printf("\n2.Delete");
                printf("\n3.Display");
                printf("\n4.Quit");
                printf("\nEnter your choice : ");
                scanf("%d",&choice);

                switch(choice)
                {
                 case 1:
                        printf("\nEnter the element for insertion : ");
                        scanf("%d",&item);
                        insert(item);
                        break;
                 case 2:
                        printf("\nDeleted element is %d\n",delete());
                        break;
                 case 3:
                        display();
                        break;
                 case 4:
                        exit(1);
                 default:
                        printf("\nWrong choice\n");
                }
        }
}

int isEmpty()
{
        if( head == NULL )
                return 1;
        else
                return 0;
}

void display()
{
    struct node *n;
    if(isEmpty())
        {
                printf("\nQueue is empty\n");
                return;
        }
    printf("\nQueue is: \n");
    n = head->next;
    do{
        printf("\n%d",n->data);
        n=n->next;
    } while (n!=head->next);
}

void insert(int item)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=item;
    if(ptr==NULL){
        printf("\nQueue full");
    }
    if( isEmpty() ) 
        {
                head=ptr;
                ptr->next=head;
        }
        else
        {
                ptr->next=head->next;
                head->next=ptr;
                head=ptr;
        }
}

int delete()
{
        int item;
        struct node *ptr;
        if( isEmpty() )
        {
                printf("\nQueue underflow\n");
        }
        if(head->next==head)  
        {
                ptr=head;
                head=NULL;
        }
        else
        {
                ptr=head->next;
                head->next=head->next->next;
        }
        item=ptr->data;
        free(ptr);
        return item;
}
