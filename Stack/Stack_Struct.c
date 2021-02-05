#include<stdio.h>
struct Stack{
    int max;
    int arr[100];
    int top;

    };
int main()
{
    struct Stack s;
    printf("\nenter the max size of stack : ");
    scanf("%d",&s.max);
    s.top = 0;
    int ele,op,flag = 1;
    do{
        printf("\nMenu\n1.Push\n2.Pop\n3.Display items\nothers to exit");
        printf("\nEnter your option : ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            if(s.top == s.max){
                printf("\nstack is full");
            }
            else{
                printf("\nEnter the element : ");
                scanf("%d",&ele);
                printf("\n Position : %d , Pushed Value  : %d ", s.top, ele);
                s.arr[s.top] = ele;
                s.top ++;
            }
            break;
        case 2:
            if(s.top == 0){
                printf("\nstack is empty");
            }
            else{
                --s.top;
                printf("\n Position : %d , Popped Value  : %d ", s.top, ele);
            }
            break;
        case 3:
            printf("\nNo. of elements in stack : %d",s.top);
            for(int i=0;i<s.top;i++){
                printf("\nPosition : %d , value : %d",i,s.arr[i]);
            }
            break;
        default:
            flag = 0;
            break;
        }
    }while(flag);
}