#include <stdio.h> //
#include <time.h> //clock()
#include<stdlib.h>//rand()
 int merge(int b[], int c[], int a[], int p, int q, int n)
	{
		int i,j,k;
		i=j=k=0;
		while(i<p && j<q)
		{

			if(b[i]<=c[j])
			{
				a[k]=b[i];
				i++;
			}
			else
			{
				a[k]=c[j];
				j++;
			}
			k++;		
		}

		if(i==p)
		{
			while(j<q)
			{
				a[k]=c[j];
				k++;
				j++;
			}
		}
		else
		{
			while(i<p && k<n)
				a[k++]=b[i++];
		}
	}

	 int  mergesort(int a[],int n)
	{ 
		int b[n/2];
		int c[n-n/2];
		int i, j;
		if(n>1)
		{          
			for(i=0;i<n/2;i++)
				b[i]=a[i];

			for(i=n/2,j=0;i<n;i++,j++)
				c[j]=a[i];
			mergesort(b, n/2);
			mergesort(c, n-n/2);
			merge(b, c, a, n/2 ,n-n/2, n);
		}
	}

	
int main() 
{ 
    // Calculate the time taken by fun() 
    int temp,min,j,i,n,a[100000],choicer;
    
    
    clock_t t; 
    printf("enter the number of elements");
    scanf("%d",&n);//n=5
    printf("Random number generator");
    		for(i=0;i<n;i++)
    		{
    		a[i]=rand()%1000;//11111%1000=111
    		printf("%d\n",a[i]);
    		}
	
    t = clock(); // t=1000
     mergesort(a,n);
     
    t = clock() - t; //1003-1000=3
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // 3.000000/18.2
    printf("entered numbers are after sorting\n");
    for(i=0;i<n;i++)
    printf("%d\n",a[i]);
    
    printf("sort function took %f seconds to execute \n",time_taken); 
    return 0; 
}

