#include <stdio.h>
#include <stdlib.h>

struct node{
    int ele;
    struct node *next;
};

void print_list(struct node *head)
{
   

    while(head)
    {
        printf("%d", head->ele);
        head = head->next;
    }

    
}

void insert_front(struct node **head, int n)
{
    struct node * new_node = NULL;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    new_node->ele = n;
    new_node->next = *head;

    *head = new_node;
}

void insert_end(struct node **head, int n)
{
    struct node * new_node = NULL;
    struct node * last = NULL;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
    }

    new_node->ele = n;
    new_node->next = NULL;

    if( *head == NULL)
    {
        *head = new_node;
        return;
    }

    last = *head;
    while(last->next) last = last->next;

    last->next = new_node;
}

void insert_after(struct node *head, int n, int after)
{
    struct node * new_node = NULL;
    struct node *tmp = head;

    while(tmp) {

      if(tmp->ele == after) { 

        new_node = (struct node *)malloc(sizeof(struct node));

        if (new_node == NULL) {
          printf("Failed to insert element. Out of memory");
        }

        new_node->ele = n;
        new_node->next = tmp->next;
        tmp->next = new_node;
        return;
      }

      tmp = tmp->next;
    }
}

void insert_before(struct node **head, int n, int before)
{
    struct node * new_node = NULL;
    struct node * tmp = *head;

    new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("Failed to insert element. Out of memory");
        return;
    }

    new_node->ele = n;

    if((*head)->ele == before)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    while(tmp && tmp->next) {

      if(tmp->next->ele == before) {
        new_node->next = tmp->next;
        tmp->next = new_node;
        return;
      }

      tmp = tmp->next;
    }

   
    free(new_node);
}

void main()
{
    int count = 0, i, ele, after, before;
    struct node * head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        printf("Enter %dth element: ", i);
        scanf("%d", &ele);
        insert_front(&head, ele);
    }

    printf("Initial List: ");
    print_list(head);

    printf("Enter a n to enter at the front of the list: ");
    scanf("%d", &ele);
    insert_front(&head, ele);

    printf("List after insertion: ");
    print_list(head);

    printf("Enter a n to enter at the end of the list: ");
    scanf("%d", &ele);
    insert_end(&head, ele);

    printf("List after insertion: ");
    print_list(head);

    printf("Enter a n to insert in the list: ");
    scanf("%d", &ele);

    printf("Insert after: ");
    scanf("%d", &after);

    insert_after(head, ele, after);

    printf("List after insertion: ");
    print_list(head);

    printf("Enter a n to insert in the list: ");
    scanf("%d", &ele);

    printf("Insert before: ");
    scanf("%d", &before);

    insert_before(&head, ele, before);
    printf("List after insertion: ");
    print_list(head);
}