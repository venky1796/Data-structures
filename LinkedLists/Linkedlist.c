#include <stdio.h> 
#include <stdlib.h> 
int size=0;
struct node { 
	int ele; 
	struct node* next; 
}; 
void print(struct node* Node) 
{ 
    while (Node!= NULL) { 
        printf(" %d \n", Node->ele); 
        Node= Node->next; 
    } 
} 
void insertAtHead(struct node** ref, int n) 
{ 
   
    struct Node* new_node = (struct node*) malloc(sizeof(struct node)); 
    new_node->data  = n; 
    new_node->next = *ref;
    *ref   = new_node; 
} 
void insertAtEnd(struct node** ref, int n) 
{ 
    struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
    struct node* prev = *ref;  
    
    
    new_node->ele  = n; 
    new_node->next = NULL; 
  
   
    if (*ref == NULL) 
    { 
       *ref = new_node; 
       return; 
    } 
  
    while (prev->next != NULL){ 
        prev = prev->next; }
    
    prev->next = new_node; 
    return; 
} 
void insertAtgivenpos(struct node** ref,int pos, int n) 
{ 
	if (pos < 1|| pos > size+1)
	printf("Invalid positon !!!!!!");

	else{
		while(pos--){
			if (pos==0){
				node *temp=(struct node *)malloc(sizeof(struct node));
				temp->ele=n;
				temp->next = *ref;
				*ref= temp;
			}
			else{
				ref= &(*ref)->next;
			}
			size++;
		}

	}

  }
int length(struct node* ref) 
{ 
    int count = 0;  
    struct node* current = ref;
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
}   
  
int main() 
{ 	int op,pos,num;
	struct node* head = NULL; 
	struct node* second = NULL; 
	struct node* third = NULL; 
	struct node* fourth = NULL;

	head = (struct node*)malloc(sizeof(struct node)); 
	second = (struct node*)malloc(sizeof(struct node)); 
	third = (struct node*)malloc(sizeof(struct node)); 
	fourth= (struct node*)malloc(sizeof(struct node));

	head->ele = 7;
	head->next = second;
	second->ele = 4; 
	second->next = third; 
	third->ele = 3; 
	third->next = fourth;
	fourth->ele = 10;
	fourth->next=NULL; 
	size=length(head);
	
 	printf("1.insertAtHead     2.insertAtEnd    3.insertAtgivenpos       4.printlist\n");
 	printf("enter your option :\n");
 	scanf("%d",&op);
 	switch(op){
 	case 1:
 			printf("enter no.\n");
 			scanf("%d",&num);
 			insertAtHead(&head,num);
 			break;	
 	case 2:
     		printf("enter no.\n");
 			scanf("%d",&num);
 			insertAtEnd(&head,num);
 			break;

 	case 3:	
 			printf("enter position\n");
 			scanf("%d",&pos);
 		    printf("enter no.\n");
 			scanf("%d",&num);
 			insertAtgivenpos(&head,pos,num);
 			break;

 	case 4:
 			print(head);
 			break;
 	default:
 			printf("enter valid option\n");

 }


	return 0; 
} 
