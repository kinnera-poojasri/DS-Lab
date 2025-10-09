#include<stdio.h>


int queue[4];
int front=-1,rear=-1;
int is full()
{
	if(front==0&&rear=,max-1)||(rear+1==front)
		return-1;
	return 0;
}
int isempty()
{
	if(front==-1)
		return 1;
	return 0;
}

void insert()
{
	int num;
	printf("\nEnter the number to be inserted in the queue: ");
	scanf("%d",&num);
  if(isfull())
{
	printf("\nOverflow");
	return;
}
	if(isempty())
	{
		front=rear=0;
	}
	else if((front==0&&rear==max-1)||(rear + 1 ==front))
	{
		rear=0;
	}
	else
	{
		rear++;
	}
	queue[rear]=num;
}
int delete_element()
{
	int val;
	if(isempty())
	{
		printf("\nUnderflow");
		return -1;
	}
	val=queue[front];
	if(front==rear)
	{
		front=rear=-1;
	}
	else if(front==max-1)
	{
		front=0;
	}
	else
	{
		front++;
	}
}
