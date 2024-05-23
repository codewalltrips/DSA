#include<stdio.h>
#include<stdlib.h>
main()
{
	int n,i,j,*k,l;
	printf("enter range=");
	scanf("%d",&n);
	k=(int*)malloc(n*sizeof(int));
	if(k==NULL)
	{
		printf("not enough memory\n");
		exit(0);
	}
	
	
	for(i=0;i<n;i++)
	{
		printf("enter element %d=",i+1);
		scanf("%d",(k+i));
	}
	int max=*(k+0);
	int min=*(k+0);
	
	for(i=0;i<n;i++)
	{
		if(max<*(k+i))
		max=*(k+i);
	}
	for(j=0;j<n;j++)
	{
		if(min>*(k+j))
		min=*(k+j);
	}
	
	printf("smallest is =%d\n",min);
	printf("largest is=%d\n",max);
}
