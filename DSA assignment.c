#include <stdio.h>
#include <stdlib.h>

//to store the multiplied numbers
typedef struct m_num_store{
    int data;
    struct m_num_store *next;
    struct m_num_store *prev;
}m_num_store ;

//to store the addition and  numbers
typedef struct num_store {
    int data;
    struct num_store *next;
    struct num_store *prev;
}num_store;

//to store first bignumber
typedef struct num1{
        int data;
        struct num1 *next;
        struct num1 *prev;
}num1;

//to store secound bignumber
typedef struct num2{
        int data;
        struct num2 *next;
        struct num2 *prev;
}num2;

//to append two big numbers from file to structre num1 && num2
int bignum_input(FILE *fp,num1 *temp1,num2 *temp2){
    char ch;int count = 0;//count initialization
    temp1->prev=NULL;
    temp2->prev=NULL;

    //input from file to struct num1 and num2
    while( fscanf (fp, "%c", &ch ) != EOF){
        if(ch == '\n')
        count++;//count incriment

        //input from file to structre num2
        else if(count == 1){
            temp2->next=malloc(sizeof(num2));
            temp2->data=atoi(&ch);
            temp2->next->prev=temp2;
            temp2=temp2->next;
        }

        //input from file to structre num1
        else if(count == 0){
            temp1->next=malloc(sizeof(num1));
            temp1->data=atoi(&ch);
            temp1->next->prev=temp1;
            temp1=temp1->next;
        }
        //if error occurse
        else
        printf("Eror");
    }
    temp1->next=NULL;
    temp2->next=NULL;
}

//Multiplicaton of two big numbers
int multiplication(FILE *fp,num1 *head1,num2 *head2,m_num_store *add){
    int sum=0,carry=0,num1_count=0,num2_count=0;
    int i,j;
    struct num1 *temp1;
    struct num2 *temp2;
    temp1=head1;
    temp2=head2;
    add->prev=NULL;

    //count the num1 && num2 size;
    while (temp1->next != NULL || temp2->next != NULL)
    {
        if(temp1->next != NULL && temp2->next != NULL){
            temp1=temp1->next;
            temp2=temp2->next;
            num1_count++;num2_count++;
        }
        else if(temp1->next != NULL){
            temp1=temp1->next;
            num1_count++;
        }
        else{
            temp2=temp2->next;
            num2_count++;
        }
    }
    temp1=head1;
    int matrix[num1_count][num2_count];//initialization of matrix
    int diagonals=num1_count+num2_count-1;//initializattion of diagonals
    int *diagonalsums=malloc(diagonals*sizeof(int));//initializattion of diagonalsum

    //multiplication step of grid method
    for(i=0;i<num1_count;i++){
        temp2=head2;
        for(j=0;j<num2_count;j++){
            matrix[i][j]=temp1->data*temp2->data;
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }

    for(i=0;i<diagonals;i++){
        diagonalsums[i]=0;
    }
    
    //diagonal sum
    for(i=0;i<num1_count;i++){
        for(j=0;j<num2_count;j++){
            diagonalsums[i+j] += matrix[i][j];
        }
    }
    
    //addition step of grid method 
    for(i=diagonals-1;i>=0;i--){
        sum=diagonalsums[i];
        if(carry>0){
            sum=sum+carry;
            carry=sum/10;
            add->next=malloc(sizeof(m_num_store));
            add->data=sum%10;
            add->next->prev=add;
            add=add->next;
        }
        else{
            carry=sum/10;
            add->next=malloc(sizeof(m_num_store));
            add->data=sum%10;
            add->next->prev=add;
            add=add->next;
        }
    }
    if(carry != 0){
        add->next=malloc(sizeof(m_num_store));
        add->data=carry;
        add->next->prev=add;
        add=add->next;
    }
    add->next=NULL;

    
    //append multiplied number to file
    fprintf ( fp, "%c",'\n');
    while(add->prev!=NULL){
        fprintf( fp, "%d", add->prev->data);
        add=add->prev;
    }
    fprintf ( fp, "%c",'\n');
}


//addition of two big numbers
int addition(FILE *fp,num1 *temp1,num2 *temp2,num_store *add){
    int sum,carry=0;//initialization of carry
    add->prev=NULL;
    //move toward end for addition of last numbers
    while (temp1->next != NULL || temp2->next != NULL)
    {
        if(temp1->next != NULL && temp2->next != NULL){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else if(temp1->next != NULL)
            temp1=temp1->next;
        else
            temp2=temp2->next;
    }
   
    //addition of two big numbers while loop
    while(temp1->prev != NULL || temp2->prev != NULL){
        if(temp1->prev == NULL && temp2->prev != NULL){
            sum=temp2->prev->data;
            temp2=temp2->prev;
        }
        else if(temp1->prev != NULL && temp2->prev == NULL){
            sum=temp1->prev->data;
            temp1=temp1->prev;
        }
        else{
            sum=temp1->prev->data+temp2->prev->data;
            temp1=temp1->prev;
            temp2=temp2->prev;
        }
        if(carry>0){
            sum=sum+carry;
            carry=sum/10;
            add->next=malloc(sizeof(num_store));
            add->data=sum%10;
            add->next->prev=add;
            add=add->next;
        }
        else{
            carry=sum/10;
            add->next=malloc(sizeof(num_store));
            add->data=sum%10;
            add->next->prev=add;
            add=add->next;
        }
    }
    if(carry != 0){
        add->next=malloc(sizeof(num_store));
        add->data=carry;
        add->next->prev=add;
        add=add->next;
    }
    add->next=NULL;

    //append aum value of two numbers
    fprintf ( fp, "%c",'\n');
    while(add->prev!=NULL){
        fprintf( fp, "%d", add->prev->data);
        add=add->prev;
    }
    fprintf ( fp, "%c",'\n');
}
int main(){
    FILE *fp;
    struct num_store *head;
    struct m_num_store *head2;
    struct num1 *first1;
    struct num2 *first2;
    head=malloc(sizeof(num_store));
    head2=malloc(sizeof(m_num_store));
    first1=malloc(sizeof(num1));
    first2=malloc(sizeof(num2));
    fp = fopen ( "input.txt", "a+" ) ;
    if ( fp == NULL )
    {
        puts ( "Cannot open file" ) ;
        exit ( 1 ) ;
    }

    //bignum_input function call
    bignum_input(fp,first1,first2);

    //addition function call
    addition(fp,first1,first2,head);

    //multiplication function call
    multiplication(fp,first1,first2,head2);
    //finally file will closed
    fclose( fp );
    return 0;
}
