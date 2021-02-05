/*
B171796
B.venkatesh
*/
#include<stdio.h>
int ele;
int push(int *a, int *top, int *max)
{

    if(*top == *max)
    {
        printf("stack is full!!!!!!!!");
    }
    else
    {
        printf("\nEnter the element: ");

        scanf("%d",&ele);
        printf("\n Position : %d , Pushed Value  : %d ", *top, ele);
        *(a+*(top)) = ele;
        *(top) = *(top) +1;
    }
}
int pop(int* top)
{
    if(*top == 0){
                printf("\nstack is empty!!!!!");
            }
            else{
                *(top) = *(top) -1;
                printf("\n Position : %d , Popped Value  : %d ", *top, ele);
            }
}
int display(int *a,int *top)
{
    printf("\nNo. of elements in stack : %d",*top);
    for(int i=0;i<*top;i++){
        printf("\nPosition : %d , value : %d",i,*(a+i));
    }
}

int main()
{
    int top = 0;
    int max;
    printf("\nenter the max size of stack : ");
    scanf("%d",&max);
    int exit = 1;
    int a[max],choice;
    do{
        printf("\n1.Push\t2.Pop\t3.print\tothers to exit");
        printf("\nEnter ur choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(&a,&top,&max);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            display(&a,&top);
            break;
        default:
            exit = 0;
            break;
        }
    }while(exit);
}
