#include<stdio.h>
#define MAX 3
	int rear=0;
	int front=0;
	int queue[MAX];
	void insert()
{
if(rear==MAX)
printf("\n the queue is overflowing");
else
{
	if(front==-1)
	front=0;
	printf("\n insert the element in the queue");
	scanf("%d",&queue[rear]);
	rear=rear+1;
}
}
void delete()
{
	if(front==rear)
	printf("\n queue is underflow:");
else
{
	printf("\n the deleted element is:",queue[front]);
	front=front+1;
}
}
void display()
{
	int i;
	if(rear==0||front==rear)
	printf("\n queue is empty");
else
{
	printf("\n queue is:");
	for(i=front;i<rear;i++)
	printf("%d\t",queue[i]);
	printf("\n");
}
}
	int main()
{
	int choice;
	while(1)
{
printf("1.insert\n");
printf("2.delete\n");
printf("3.display\n");
printf("4.exit\n");
printf("enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
exit(1);
default:printf("\n invalid choice");
}
}
}
