#include <stdio.h>

int main() 
{
    int mincost = 0, n, i, j, ne, a = 0, b = 0, min, u = 0, v = 0;
    int cost[10][10], visited[10];
    
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    
    printf("Enter the cost matrix\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    
    for(i = 2; i <= n; i++)
        visited[i] = 0;
    visited[1] = 1;
    ne = 1;
    
    while(ne < n)
    {
        for(min = 999, i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i] == 0)
                        continue;
                    else
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if(visited[u] == 0 || visited[v] == 0)
        {
            printf("\n %d edge (%d, %d)=%d", ne++, a, b, min);
            mincost = mincost + min;
            visited[v] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
     printf("\nThe minimum cost of spanning tree is = %d", mincost);
     return 0;
}


