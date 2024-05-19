    #include <stdio.h>  
      
    //Represent a node of the singly linked list  
    struct node{  
        int data;  
        struct node *next;  
    };      
       
    //Represent the head and tail of the singly linked list  
    struct node *head, *tail = NULL;  
       
    //addNode() will add a new node to the list  
    void addNode(int data) {  
        //Create a new node  
        struct node *newNode = (struct node*)malloc(sizeof(struct node));  
        newNode->data = data;  
        newNode->next = NULL;  
          
        //Checks if the list is empty  
        if(head == NULL) {  
            //If list is empty, both head and tail will point to new node  
            head = newNode;  
            tail = newNode;  
        }  
        else {  
            //newNode will be added after tail such that tail's next will point to newNode  
            tail->next = newNode;  
            //newNode will become new tail of the list  
            tail = newNode;  
        }  
    }  
       
    //removeDuplicate() will remove duplicate nodes from the list  
    void removeDuplicate() {  
        //Node current will point to head  
        struct node *current = head, *index = NULL, *temp = NULL;  
          
        if(head == NULL) {  
            return;  
        }  
        else {  
            while(current != NULL){  
                //Node temp will point to previous node to index.  
                temp = current;  
                //Index will point to node next to current  
                index = current->next;  
                  
                while(index != NULL) {  
                    //If current node's data is equal to index node's data  
                    if(current->data == index->data) {  
                        //Here, index node is pointing to the node which is duplicate of current node  
                        //Skips the duplicate node by pointing to next node  
                        temp->next = index->next;  
                    }  
                    else {  
                        //Temp will point to previous node of index.  
                        temp = index;  
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }          
        }  
    }  
       
    //display() will display all the nodes present in the list  
    void display() {  
        //Node current will point to head  
        struct node *current = head;  
        if(head == NULL) {  
            printf("List is empty \n");  
            return;  
        }  
        while(current != NULL) {  
            //Prints each node by incrementing pointer  
            printf("%d ", current->data);  
            current = current->next;  
        }  
        printf("\n");  
    }  
          
     main()  
    {  
        //Adds data to the list  
        addNode(1);  
        addNode(2);  
        addNode(3);  
        addNode(2);  
        addNode(2);  
        addNode(4);  
        addNode(1);  
          
        printf("Originals list: \n");  
        display();  
          
        //Removes duplicate nodes  
        removeDuplicate();  
          
        printf("List after removing duplicates: \n");  
        display();  
         
    }  
