#include<stdio.h>
#include<stdlib.h>
main()
{
	int n,i,j,*k,l,t,r,s;
	printf("enter a range=");
	scanf("%d",&n);
	k=(int*)malloc(n*sizeof(int));
	if(k==NULL)
	{
		printf("not enough space\n");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		printf("enter element %d=",i+1);
		scanf("%d",(k+i));
	}
	printf("Only palindromes are=\n");
	for(i=0;i<n;i++)
	{
		l=*(k+i);
		s=0;
		while(l>0)
		{
			r=l%10;
			s=s*10+r;
			l=l/10;
		}
		if(*(k+i)==s)
		printf("%d\t",*(k+i));
	}
}
