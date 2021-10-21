#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 100

struct student
{
	int id;
	int age;
	int marks;
};
	void accept_input(struct student s1);
{
	printf("\n enter the id:");
	scanf("%d",&s1->id);
	printf("\n enter the age:");
	scanf("%d",&s1->age);
	printf("\n enter the marks:");
	scanf("%d",&s1->marks)
	void accept_output(struct student s1);
{
	printf("\n student details are:");
	printf("\n id-%d",s1->id);
	printf("\n id-%d",s1->age);
	printf("\n id-%d",s1->marks);
}
int main()
{
	struct student s[SIZE];
	int no_of_students,i;
	printf("\n enter the no_of_students:");
	scanf("%d",&no_of_students);
	for(i=0;i<no_of_students;i++)
{
	accept_input(s[i]);
}
	for(i=0;i<no_of_students;i++)
{
	display_output(s[i]);
}
	return 0;
}
