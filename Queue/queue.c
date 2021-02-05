 /*
B171796
B.venkatesh
*/ 
#include<stdio.h>
#include<stdlib.h>
int ele;
int arr[5];
int front = 0;
int rear=0;

void enqueue()
{
    if(front == 5)
    {
        printf("\nSTACK IS FULL");
    }
    else
    {
        printf("\nenter the element: ");
        scanf("%d",&ele);
        for(int i=front;i>0;i--)
        {
            arr[i] = arr[i-1];
        }
        arr[rear] = ele;
        front++;
    }
}

void dequeue()
{
    if(rear == front)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        printf("\npopped value is %d at position %d ",arr[front-1],front-1);
        front--;
    }
}

void display()
{
    printf("\n");
    for(int i=0; i<front;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void main()
{
    int choice;
    while(1)
    {
        printf("\nQUEUE\n1.ENQUEUE\t2.DEQUEUE\t3.DISPLAY\tOTHERS TO EXIT\tENTER THE OPTION : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
            break;
        }
    }


}
