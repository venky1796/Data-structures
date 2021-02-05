/*
B171796
B.venkatesh
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
	int ele;
	struct node* next;
	struct node* prev;
};

void InsertAtHead(struct node** ref, int n)
{
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp->ele = n;
	temp->next = (*ref);
	temp->prev = NULL;
	if ((*ref) != NULL)
		(*ref)->prev = temp;
	(*ref) = temp;
}

void insertAtend(struct node** ref, int n)
{
	
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node* last = *ref;
	
	temp->ele = n;
	temp->next = NULL;
if (*ref == NULL) {
		temp->prev = NULL;
		*ref = temp;
		return;
	}

while (last->next != NULL)
		last = last->next;
last->next = temp;
temp->prev = last;
return;
}
void insertAtgivenpos(struct Node** ref,int pos, int n) 
{ 
	if (pos < 1|| pos > size+1)
	printf("Invalid positon !!!!!!");

	else{
		while(pos--){
			if (pos==0){
				node *temp=(struct node *)malloc(sizeof(struct node));
				temp->ele=n;
				*ref->prev=temp;
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

 int length(struct node *temp) 
{ 
   int c = 0; 
   while (temp != NULL) 
   { 
       c++; 
       temp = temp->next; 
   } 
   return c; 
} 
void print(struct node* node)
{
	struct node* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %d ", node->ele);
		last = node;
		node = node->next;
	}

	printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf(" %d ", last->ele);
		last = last->prev;
	}
}


int main()
{	int op,num,len,pos;

	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	second= (struct node*)malloc(sizeof(struct node));
	third= (struct node*)malloc(sizeof(struct node));

	head->ele=4;
	head->prev=NULL;
	head->next=second;

	second->ele=7;
	second->prev=head;
	second->next=third;

	third->ele=8;
	third->prev=second;
	third->next=NULL;
	
	printf("1.InsertAtHead  2.insertAtend  3.insertAtgivenpos	4.printthelist\n");
	printf("enter your option : \n");
	scanf("%d",&op);
	switch(op)
	{case 1:
			printf("enter element");
			scanf("%d",&num);
			InsertAtHead(&head,num);
			break;

	case 2:
			printf("enter element");
			scanf("%d",&num);
			insertAtend(&head,num);
			break;

	case 3:
			printf("enter element");
			scanf("%d",&num);
			printf("enter position");
			scanf("%d",&pos);
			len=length(head);
			insertAtgivenpos(&head,pos,num);
			break;

	case 4:
			print(head);
			break;
	default:
			printf("enter any Valid option");


	}

	return 0;
}
