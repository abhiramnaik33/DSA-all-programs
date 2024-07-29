#include <stdio.h>
int main(){
    int front=0,rear=0,choice;
    int queue[5];
    int i = 0  ;
    while(1){
    printf("Enter your choice\n 1.Insert\n 2.Delete\n 3.Display\n");
    scanf("%d",&choice);
    if (choice == 1){
        printf("enter the number\n");
        scanf("%d",&queue[rear]);
        rear++;
    }
    else if(choice == 2){
        printf("the element removed from the queue is %d\n",queue[front]);
        front++;
    }
    else if(choice == 3){
    	for(i=front;i<rear;i++);
    	printf("the elements are %d\n",queue[i]);
		}
    else
    printf("wrong choice");
   
}
}
