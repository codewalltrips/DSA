
#include<stdio.h>
#include<stdlib.h>

/*structure of linked list*/
struct Node{
  
  int data;// linked list data 
  struct Node*next;// pointer field
  
};

/* Function declaration section here */
void insert_data(struct Node**,int);
void show_data(struct Node*);
void remove_node(struct Node**);
void bubble_sort(struct Node*);


/*Help of this function create new linked list node. 
And there are inserted this element on end position of given linked list*/
void insert_data(struct Node**root,int value){

  /* create new memory block using malloc function. */
  struct Node*temp=NULL,*new_node=(struct Node*)malloc(sizeof(struct Node));
  
  /* check new create memory are allocate or not. */
  if(new_node)
  {   

      /*Assign data and next pointer value to newly created node.*/
    new_node->data=value;
    new_node->next=NULL;

    if(*root==NULL){
      /*When linked list are empty. Insert first node*/
      *root=new_node;
    }
    else{
      /*When linked list are not empty*/

      /*linked list first node address assign on temp pointer*/
      temp=*root;
      
      /*This will loop find last node of exist linked list*/
      while(temp->next){
        /*move temp pointer on next memory block*/
        temp=temp->next;  
      }
      
      /*assign this newly created node on end of list*/
      temp->next=new_node;
      
    }         
  }
  else
  {
    /* When malloc function not create memory block then. */
    printf("\n Memory overflow please try again..!");
  }
}


/* Help of this function showing all element of single linked list */
void show_data(struct Node*temp){
  
  if(temp==NULL){
    /*linked list are empty*/
    printf("Empty linked List\n");
  }
  else
  {
    /*When linked list are not empty*/
    printf("linked list :");
    while(temp)
    {
      /*Print linked list data*/
      printf("%d  ",temp->data);

      /*Move next memory block*/
      temp=temp->next;
    }
    
  }
}
/*Help of this function removing all linked list element.*/
void remove_node(struct Node**root){

  if(*root){

    struct Node*temp=*root;
    
    while(temp){

      /*Moving root pointer to on next memory block.*/
      *root=temp->next;

      /*before removing that linked node assign
       next pointer value are null.*/
      temp->next=NULL;
      
      /*Free linked list node element*/
      free(temp);
      
      temp=*root;
    }
    printf("\n\n Free nodes of linked linked \n");
  }
  else{
    /* When linked list is empty */
    printf("\n linked list is empty \n");
  }
  
}

/*Buuble sort on linked list*/
void bubble_sort(struct Node*temp){
  struct Node*help=NULL,*store=temp;
  int swap_data;
  while(temp){
    help=store;
    while(help){
    
      if(help->next && help->data > help->next->data){
        /*swap node data*/
        swap_data=help->data;
        help->data=help->next->data;
        help->next->data=swap_data;
      }
      /*Move next node of linked list*/
        help=help->next;
    }
    /*Move next node of linked list*/
    temp=temp->next;
  }
}



int main(){

    
  struct Node*root=NULL;
   
  /* Assume that following data are inserted */
    
  /* 89-->66-->12-->11-->61-->17-->84-->NULL*/
  
    insert_data(&root,89);
    insert_data(&root,66);
    insert_data(&root,12);
    insert_data(&root,32);
    insert_data(&root,11);
    insert_data(&root,61);
    insert_data(&root,17);
    insert_data(&root,84);

   printf("\n Before Bubble sort:"); 
   /*show all element of given linked list.*/
   show_data(root);
   
   bubble_sort(root);
   printf("\n After Bubble sort :"); 

  /*show all element of given linked list.*/
  show_data(root);
  
  /*removing linked list node*/
    remove_node(&root);
    
 
}
