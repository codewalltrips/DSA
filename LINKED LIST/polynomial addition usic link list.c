#include <stdio.h>
#include<conio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct pnode//using typedef so that we do not need to write the word 'struct' always;
   {
    float coef;
    int exp;
    struct pnode *next;
   }p;//p is the object here(normal type,not pointer type);
p *getnode();//getnode is a structure type pointer type function which operates with structure;
//Main function starts here
main()
   {
    p *p1,*p2,*p3;//(pointer type objects)
    p *getpoly(),*add(p*,p*);
    void display(p*);//we can declare this both inside or outside;
    
    printf("\n Enter first polynomial");
    p1=getpoly();
    printf("\n Enter second polynomial");
    p2=getpoly();
    printf("\nThe first polynomial is");
    display(p1);
    printf("\nThe second polynomial is");
    display(p2);
    p3=add(p1,p2);
    printf("\nAddition of two polynomial is :\n");
    display(p3);
   }
 
/*Funtion to get polynomial*/
p *getpoly()
  {
    p *temp,*New,*last;
    int flag,exp;
    char ans;
    float coef;
    temp=NULL;
    flag=1;
    printf("\nenter the polynomial in descending order of exponent");
    do
      {
        printf("\nenter the coef & exponent of a term");
        scanf("%f%d",&coef,&exp);
        New=getnode();
        if(New==NULL)
		
        printf("\nmemory cannot be allocated");
        New->coef=coef;
        New->exp=exp;
        
		if(flag==1)//condition to copy address of new into temp just for the first time;
          {
            temp=New;
            last=temp;
            flag=0;
           }
        else
          {
            last->next=New;
            last=New;
           }
        printf("\ndou want to more terms");
       ans=getch();
        }
      while(ans=='y');
      return(temp);
}
/*Function to get the Nodes of Polynomial*/
p *getnode()
  {
    p *temp;
    temp= (p*)malloc (sizeof(p));
    temp->next=NULL;
    return(temp);
  }
/*Function to display Polynomial*/
void display(p*head)
  {
    p*temp;
    temp=head;
    if(temp==NULL)
    printf("\npolynomial empty");
    while(temp->next!=NULL)
      {
        printf("%0.1fx^%d+",temp->coef,temp->exp);
        temp=temp->next;
       }
    printf("\n%0.1fx^%d",temp->coef,temp->exp);//why write the same statement twice-to write the last polynomial?
    
   }
/*Function to add Polynomials*/
p*add(p*first,p*second)
  {
    p *p1,*p2,*temp,*dummy;
    char ch;
    float coef;
    p *append(int,float,p*);
    p1=first;
    p2=second;
    temp=(p*)malloc(sizeof(p));
    if(temp==NULL)
    printf("\nmemory cannot be allocated");
    dummy=temp;
    while(p1!=NULL&&p2!=NULL)
      {
        if(p1->exp==p2->exp)
              {
            coef=p1->coef+p2->coef;
            temp=append(p1->exp,coef,temp);
            p1=p1->next;
            p2=p2->next;
               }
        else

	    if(p1->exp)//or we can write (p1->exp<p2->exp)//if there is some value in the exponential part,then it is valid;//5x^3,4x^2;
          {
            coef=p2->coef;//=4;
            temp=append(p2->exp,coef,temp);//3,4
            p2=p2->next;
           }
        else
        if(p1->exp>p2->exp)
          {
            coef=p1->coef;
            temp=append(p1->exp,coef,temp);
            p1=p1->next;
           }
       }
    while(p1!=NULL)
      {
        temp=append(p1->exp,p1->coef,temp);//is this basically storing the 5x^3 in temp directly?
        p1=p1->next;
        }
    while(p2!=NULL)
      {
        temp=append(p2->exp,p2->coef,temp);
        p2=p2->next;
        }
    temp->next=NULL;
    temp=dummy->next;
    free(dummy);// weare freeing dummy which contains temp,since temp already containd dummy.
    return(temp);
   }
/*Function to append the coefficients with Polynomial*/
p*append(int Exp,float Coef,p*temp)
  { 
    p*New,*dum;
    New=(p*)malloc(sizeof(p));
    if(New==NULL)
    printf("\ncannot be allocated");
    New->exp=Exp;
    New->coef=Coef;
    New->next=NULL;
    dum=temp;
    dum->next=New;
    dum=New;
    return(dum);
  }
