#include<stdio.h>
#include<stdlib.h>
main()
{
	int i,j,*k,l,n;
	k=(int*)calloc(n,sizeof(int));
	printf("enter a range=");
	scanf("%d",&n);
	if(k==NULL)
	{
		printf("not enough space\n");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		printf("enter element %d=",i+1);
		scanf("%d",k+i);
	}
	printf("EVEN NUMBERS ARE=\n");
	for(i=0;i<n;i++)
	{
		if(*(k+i)%2==0)
		printf("%d\t",*(k+i));
	}
	printf("\nODD NUMBERS ARE=\n");
	for(i=0;i<n;i++)
	{
		if(*(k+i)%2!=0)
		printf("%d\t",*(k+i));
	}
}
