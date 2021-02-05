 /*
B171796
B.venkatesh
*/
#include<stdio.h>
void main(){
    int top = 0 ;
    int max,flag = 1;
    printf("\nenter the max size of stack : ");
    scanf("%d",&max);
    int stack[max];
    int ele,op;
    do{
        printf("\n1.Push\t2.Pop\t3.print\tothers to exit");
        printf("\nEnter your option: ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            if(top == max){
                printf("\nstack is full");
            }
            else{
                printf("\nEnter the element : ");
                scanf("%d",&ele);
                printf("\n Position : %d , Pushed Value  : %d ", top, ele);
                stack[top++] = ele;
            }
            break;
        case 2:
            if(top == 0){
                printf("\nstack is empty!!!");
            }
            else{
                --top;
                printf("\n Position : %d , Popped Value  : %d ", top, ele);
            }
            break;
        case 3:
            printf("\nNo. of elements in stack : %d",top);
            for(int i=0;i<top;i++){
                printf("\nPosition : %d , value : %d",i,stack[i]);
            }
            break;
        default:
            flag = 0;
            break;
        }
    }while(flag);
}
