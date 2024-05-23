#include<stdio.h>
#include<stdlib.h>
main()
{
	int n,i,j,*k,l;
	printf("enter a range=");
	scanf("%d",&n);
	k=(int*)calloc(n,sizeof(int));
	if(k==NULL)
	{
		printf("not enough memory \n");
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		printf("enter element %d=",i+1);
		scanf("%d",(k+i));
	}
	int a[n];
	l=n-1;
	for(i=0;i<n;i++)
	{
		a[l]=*(k+i);
		l--;
	}
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
