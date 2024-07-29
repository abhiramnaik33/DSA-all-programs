#include <stdio.h>

int main() {
    int vert=6,i,j,flag=0;
    //printf("Enter the number of vertices of the graph: ");
    //scanf("%d", &vert);

    int matrix[6][6]={
							{0,0,0,0,1,0},
							{0,0,0,0,0,0},
							{0,0,0,0,1,0},
							{0,0,0,0,1,0},
							{1,0,1,1,0,0},
							{0,0,0,0,0,0}
							};

    /*printf("\nEnter the adjacency matrix of the graph:\n");
    for ( i = 0; i < vert; i++) {
        for ( j = 0; j < vert; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }*/
    printf("\nthe adjacency matrix of the graph:\n");
	for ( i = 0; i < vert; i++) {
        for ( j = 0; j < vert; j++) {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
	}
	
    printf("\nThe matrix is:\n");
    for ( i = 0; i < vert; i++) {
    	flag=0;
        for ( j = 0; j < vert; j++) {
        	if(matrix[i][j]==1){
        		flag=1;
				break;	
			}
        
        }
        if(flag==0){
        	printf("%d is the isolated vertex\n",i);
		}
    }
    
    return 0;
}
