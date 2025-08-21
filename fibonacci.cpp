#include<stdio.h>
int main()
{
	int a=0,b=1,c,n,i;
    printf("enter the value of n:");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		c=a+b;
		printf("%d\n",c);
		a=b;
		b=c;
	}
