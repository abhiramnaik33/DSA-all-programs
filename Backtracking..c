//Backtracking
#include <stdio.h>
	#include <stdlib.h>
	int x[10];
	int place(int k,int i)
	{
		int j;
		for(j=1;j<=k-1;j++)
		if(x[j]==i || abs(x[j]-i)==abs(j-k))
		return 0;
		return 1;
	}
	void display(int n)
	{
		int k,i,j;
		char cb[n][n];
		for(k=1;k<=n;k++)
		cb[k][x[k]]='Q';
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
			if(j!=x[i])
			cb[i][j]='-';
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			printf("%c\t",cb[i][j]);
			printf("\n");
		}
		printf("\n\n");
	}
	void NQueens(int k,int n)
	{
		int i;
		for(i=1;i<=n;i++)
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
			printf("Solution\n");
			display(n);
			}
			else
			NQueens(k+1,n);
		}
	}
	int main(void)
	{
		int n,k=1;
		printf("Enter the dimensions of the chessboard\n");
		scanf("%d",&n);
		if(n==2 || n==3)
		{
			printf("No solution\n");
			exit(0);
		}
		NQueens(k,n);
		return 0; 
	}

