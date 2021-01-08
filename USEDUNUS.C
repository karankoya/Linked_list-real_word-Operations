#include<stdio.h>
#include<conio.h>

struct USED_PROCESSES
{
	int value;
	struct USED_PROCESSES *next;
};

struct UNUSED_PROCESSES
{
	int value;
	struct UNUSED_PROCESSES *next;
};

typedef struct USED_PROCESSES used;

used *start = NULL;
int count = 0;

typedef struct UNUSED_PROCESSES unused;

unused *start1 = NULL;
int count1 = 0;

void insertIntoUnused()
{
	unused *newnode;
	newnode = (unused *)malloc(sizeof(unused));
	printf("\nEnter Process Address:- ");
	scanf("%d",&newnode->value);
	newnode->next = start1;
	start1 = newnode;
	printf("\nInserted");
	count1++;
}

void transferUnusedUsed()
{
	unused *temp;
	used *newnode;
	int val = 0;

	if(count1 == 0)
	{
		printf("\nLinked List Underflow");
	}
	else if(count1 == 1)
	{
		temp = start1;
		val = temp->value;
		start1 = NULL;
		count1--;

		newnode = (used *)malloc(sizeof(used));
		newnode->value = val;
		newnode->next =  start;
		start = newnode;
		count++;
		printf("\nTransferred");
	}
	else
	{
		temp = start1;
		val = temp->value;
		start1 = start1->next;
		count1--;

		newnode = (used *)malloc(sizeof(used));
		newnode->value = val;
		newnode->next =  start;
		start = newnode;
		count++;
		printf("\nTransferred");
	}
}
void transferUsedUnused()
{
	used *temp;
	unused *newnode;
	int val = 0;

	if(count == 0)
	{
		printf("\nLinked List Underflow\n");
	}
	else if(count == 1)
	{
		temp = start;
		val = temp->value;
		start = NULL;
		count--;

		newnode = (unused *)malloc(sizeof(unused));
		newnode->value = val;
		newnode->next =  start1;
		start1 = newnode;
		count1++;
		printf("\nTransferred");
	}
	else
	{
		temp = start;
		val = temp->value;
		start = start->next;
		count--;

		newnode = (unused *)malloc(sizeof(unused));
		newnode->value = val;
		newnode->next =  start1;
		start1 = newnode;
		count1++;
		printf("\nTransferred");
	}
}

void showUnused()
{
	unused *temp;
	int i = 0;

	if(count1 == 0)
	{
		printf("\nLINKED LIST UNDERFLOW\n");
	}
	else
	{
		printf("\Number of new/blocked nodes:- %d\n",count1);
		temp = (unused *)malloc(sizeof(unused));
		for(temp = start1,i=0; i<count1; temp = temp->next,i++)
		{
			printf("%d -> ",temp->value);
		}
		printf("NULL");
	}
}

void showUsed()
{
	used *temp;
	int i = 0;

	if(count == 0)
	{
		printf("\nLINKED LIST UNDERFLOW\n");
	}
	else
	{
		printf("\Number of ready nodes:- %d\n",count);
		temp = (unused *)malloc(sizeof(used));
		for(temp = start,i=0; i<count; temp = temp->next,i++)
		{
			printf("%d -> ",temp->value);
		}
		printf("NULL");
	}
}

void main()
{
	int ch = 0,i,val;

	clrscr();

	printf("\nYou can follow these operations with our list:- \n");
	printf("\n1. Insert process for processing\n");
	printf("\n2. Take process to ready state\n");
	printf("\n3. Take the process to Blocked State\n");
	printf("\n4. Show new/blocked process\n");
	printf("\n5. Show ready process\n");
	printf("\n6.EXIT\n");

	while(ch != 6)
	{
		printf("\nEnter your choice:- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertIntoUnused(val);
				break;

			case 2: transferUnusedUsed();
				break;

			case 3: transferUsedUnused();
				break;

			case 4: showUnused();
				break;

			case 5: showUsed();
				break;

			case 6: printf("\nSIGNING OFF\n");
				break;
		}
	}
	getch();
}