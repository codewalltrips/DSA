#include<stdio.h>
#include<stdlib.h>
main()
{
	int n,i,j,*k,l,t,r,s,num;
	printf("enter range=");
	scanf("%d",&n);
	/*-------------------------*/
	k=(int*)malloc(n*sizeof(int));
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
	printf("MAGIC NUMBERS ARE=\n");
	for(i=0;i<n;i++)
	{
		l=*(k+i);
		while(l>9)
		{
			num=l;
			s=0;
			while(num>0)
			{
				r=num%10;
				s=s+r;
				num=num/10;
			}	
			l=s;
		}
		if(s==1)
		printf("%d\t",*(k+i));
	}
}
