#include <stdlib.h>
#include <stdio.h>

struct node {
    int info;
    struct node *next;
};
struct node *start = NULL;
struct node *start2 = NULL;

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
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void create2()
{
    struct node *newnode;
    struct node *temp;
     int s, y;
    printf("enter elements to create list 2\n");
    do
    {
        printf("Enter integer  : \n");
        scanf("%d", &s);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->info = s;
        if (start2 == NULL)
        {
            newnode->next = NULL;
            start2 = newnode;
            printf("first node of linked list created\n");
        }
        else
        {
            temp = start2;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
            printf("Node created\n");
        }
        printf("do u want to continue adding:0 or 1\n");
        scanf("%d", &y);
    } while (y != 0);
}

void display()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nList is empty:");
        return;
    }
    else
    {
        ptr = start;
        printf("\nThe List elements are:");
        while (ptr != NULL)
        {
            printf("\n%d", ptr->info);
            ptr = ptr->next;
        }
    }
}

void reverse ()
{
    struct node *prev = NULL;
    struct node *current = start;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    start = prev;
}

void sort()
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->info > ptr1->next->info)
            {
                int temp = ptr1->info;
                ptr1->info = ptr1->next->info;
                ptr1->next->info = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void concat ()
{
     struct node *ptr;
    if (start == NULL)
    {
        start = start2;
    }
    if (start2 == NULL)
    {
        start2 = start;
    }
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = start2;
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
        case 5:
            create2();
            concat();
            display();
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
