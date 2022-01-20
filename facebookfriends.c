#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head;

void insert(int likes){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = likes;
    ptr -> next = head;
    ptr -> prev = NULL;
    if(head!=NULL){
        head->prev = ptr;
    }
    head = ptr;
}

int maxLikes(struct node *head) {
    int max = head->data;
    while(head!=NULL){
        if(head->data>max){
            max=head->data;
        }
        head=head->next;
    }
    return max;
}

void display(struct node *nodeptr) {
    while(nodeptr!=NULL){
        printf("\n%d",nodeptr->data);
        nodeptr = nodeptr->next;
    if(nodeptr!=NULL){
        printf("\n");
        }
    }
}

int main(){
    int choice, num, likes;
    char name;
    head = NULL;
    while(1){
    printf("\n----MENU----");
    printf("\n 1.Add Facebook Friends");
    printf("\n 2.Display Facebook Friends");
    printf("\n 3.Display Higest Likes");
    printf("\n Enter your choice:");
    scanf("%d", &choice);
    switch(choice){
        case 1: printf("\nEnter name: ");
                scanf("%s",&name);
                printf("\nEnter phone number: ");
                scanf("%d",&num);
                printf("\nEnter likes: ");
                scanf("%d",&likes);
                insert(likes);
                break;
        case 2: 
        printf("\n----Facebook friend list----");
        display(head);
                break;
        case 3: printf("\nHighest likes in friend list is friend %c : %d",name, maxLikes(head));
                break;
        case 4: exit(0);
    }
    }
}
