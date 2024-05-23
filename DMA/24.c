#include<stdio.h>
#include<stdlib.h>
main()
{
	int i,n,j,*k,l,r,a,b,s;
	printf("enter range=");
	scanf("%d",&n);
	k=(int*)calloc(n,sizeof(int));
	/*----------------------------*/
	if(k==NULL)
	{
		printf("not enough space\n");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		printf("enter elemnt %d=",i+1);
		scanf("%d",k+i);
	}
	/*----------------------------*/
	for(i=0;i<n;i++)
	{
		
		l=*(k+i);
			s=0;
		while(l>0)
		{
			r=l%10;
			a=1;
		
			for(j=1;j<=r;j++)
			{
				a=a*j;
			}
			s=s+a;
			l=l/10;
		}
		if(s==*(k+i))
		printf("%d\t",*(k+i));
		
	}
}
