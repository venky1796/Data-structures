#include<stdio.h>
#include<stdlib.h>
struct node
{
  int ele;
  struct node* lchild;
  struct node* rchild;
};

struct node* root = NULL;

struct queue
{
    struct node* arr[1000];
    int front;
    int rear;
};


void push(struct queue*a, struct node*val)
{
    a->arr[a->rear] = val; 
    (a->rear)++;
}

void pop(struct queue*a)
{
    if(a->front!=a->rear)
    {
        for(int i=0;i<(a->rear-1);i++)
        {
            a->arr[i] = a->arr[i+1];
        }
        (a->rear)--;
    }
}

void insert(struct queue *a)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nenter the value : ");
    scanf("%d",&temp->ele);
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(root == NULL)
    {
        root = temp;
        push(a,root);
    }
    else
    {
        struct node* temp1;
        
        while(1)
        {
            temp1 = (a->arr[a->front]);
            if(temp1->lchild == NULL)
            {
                temp1->lchild = temp;
                push(a,temp);
                break;
            }
            else if(temp1->rchild == NULL)
            {
                temp1->rchild = temp;
                push(a,temp);
                break;
            }
            if((temp1->lchild !=NULL) && (temp1->rchild!=NULL))
            {
                pop(a);
            }
            
        }
        
    }
    
}


void inorder(struct node *t)
{
    if(t->lchild)
        inorder(t->lchild);
    printf("%d ",t->ele);
    if(t->rchild)
        inorder(t->rchild);
}

void display(struct node*t)
{
    inorder(t);
}

int COUNT =10;
void print2DUtil(struct node *root, int space) 
{ 
    if (root == NULL) 
        return; 
    space += COUNT; 
    print2DUtil(root->rchild, space); 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->ele); 
  
    print2DUtil(root->lchild, space); 
}



void print()
{
    if(root==NULL)
    {
        printf("\nno elements");
    }
    else
    {
        struct queue *b;
    b = (struct queue*)malloc(sizeof(struct queue));
    b->front = 0;
    b->rear = 0;
    b->arr[(b->rear)++] = root;
    struct node *temp;
    while((b->rear)>0)
    {
        temp = b->arr[b->front];
        printf("%d ",temp->ele);
        if(temp->lchild)
            push(b,temp->lchild);
        if(temp->rchild)
            push(b,temp->rchild);
        pop(b);
        
    }
    printf("\n");
    }
    
    
    
}

void check(struct node* adress,int ele)
{
    if(ele == 200)
    {
        if(root->lchild==NULL && root->rchild==NULL)
        {
            adress->lchild = root;
            adress->ele = 1;
        }
        else
        {
            struct queue *b;
            b= (struct queue*)malloc(sizeof(struct queue));
            b->front =0;
            b->rear = 0;
            push(b,root);
            struct node*temp;
            while((b->rear)>0)
            {
                temp = b->arr[b->front];
                if(temp->lchild)
                {
                    push(b,temp->lchild);
                    adress->lchild = temp;
                    adress->ele = 2;
                }
                if(temp->rchild)
                {
                    push(b,temp->rchild);
                    adress->lchild = temp;
                    adress->ele = 3;
                }
                pop(b);
            }
        }
    }
    else
    {
        if(root->ele == ele)
        {
            adress->lchild = root;
            adress->ele = 1;
        }
        else
        {
            struct queue* b;
            b = (struct queue*)malloc(sizeof(struct queue));
            b->front = 0;
            b->rear = 0;
            push(b,root);
            struct node* temp;
            while((b->rear)>0)
            {
                temp = b->arr[b->front];
                if(temp->lchild->ele == ele)
                {
                    adress->lchild = temp;
                    adress->rchild = NULL;
                    adress->ele = 2;
                    break;
                }
                else if(temp->rchild->ele == ele)
                {
                    adress->lchild = temp;
                    adress->rchild = NULL;
                    adress->ele = 3;
                    break;
                
                }
                else if(temp->lchild !=ele && temp->lchild !=NULL )
                {
                    push(b,temp->lchild);
                }
                else if(temp->rchild!=ele && temp->rchild!=NULL)
                {
                    push(b,temp->rchild);
                }
                pop(b);
            }
        }
    }
}


void delete_by_value()

{
    if(root == NULL)
    {
        printf("\nno elements");
    }
    else
    {
        int ele,i,j;
        printf("\nenter the element");
        scanf("%d",&ele);
        struct node* temp,*prev;
        temp = (struct node*)malloc(sizeof(struct node));
        prev = (struct node*)malloc(sizeof(struct node));
        printf("\nnow");
        check(temp,ele);
        check(prev,200);
        i = temp->ele;
        j = prev->ele;
        printf("\nherere");
        printf("\n%d adress , %d position",temp->lchild->ele,temp->ele);
        printf("\n%d adress-last , %d position",prev->lchild->ele,prev->ele);
        
        if(i==1||i==2||i==3)
        {
            printf("\nelement found");
            if(i==1 && j==1)
            {
                root = NULL;
            }
            else if(i==1 &&(j==2 || j==3))
            {
                if(j==2)
                {
                    temp->lchild->ele = prev->lchild->lchild->ele;
                    prev->lchild->lchild = NULL;
                    free(prev->lchild->lchild);
                }
                if(j==3)
                {
                    temp->lchild->ele = prev->lchild->rchild->ele;
                    prev->lchild->rchild = NULL;
                    free(prev->lchild->rchild);
                }
                
            }
            else if(i==2 &&(j==2 || j==3))
            {
                if(j==2)
                {
                    temp->lchild->lchild->ele = prev->lchild->lchild->ele;
                    prev->lchild->lchild = NULL;
                    free(prev->lchild->lchild);
                }
                if(j==3)
                {
                    temp->lchild->lchild->ele = prev->lchild->rchild->ele;
                    prev->lchild->rchild = NULL;
                    free(prev->lchild->rchild);
                }
            }
            else if(i==3 && (j==2||j==3))
            {
                if(j==2)
                {
                    temp->lchild->rchild->ele = prev->lchild->lchild->ele;
                    prev->lchild->lchild = NULL;
                    free(prev->lchild->lchild);
                }
                if(j==3)
                {
                    temp->lchild->rchild->ele = prev->lchild->rchild->ele;
                    prev->lchild->rchild = NULL;
                    free(prev->lchild->rchild);
                }
            }
        }
        
    }
}



int main()
{
    struct queue *a;

    a = (struct queue*)malloc(sizeof(struct queue));
    a->front = 0;
    a->rear = 0;
    struct node *t = root;
    int op;
    while(1)
    {
        printf("1.insert\t\t2.delete_value\t\t3.print\t\tanyOtherToEXIT\n");
        printf("enter Your option :\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            insert(a);
            break;
        case 2:
            delete_by_value();
            break;
        case 3:
            print();
            break;
        default:
            exit(0);
            break;
        }
    }print2DUtil(t,0);
   }

