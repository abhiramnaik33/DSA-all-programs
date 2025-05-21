#include <stdio.h>
#include <stdlib.h>

#define INF 999

void dijikstras(int cost[][100], int dist[], int n, int v);

int main() {
    int n, source, i, j;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    int cost[100][100];
    int dist[100];
    
    printf("Enter the cost adjacency matrix\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    
    printf("source\n");
    scanf("%d", &source);
    dijikstras(cost, dist, n, source);
    
    for(i = 1; i <= n; i++)
        if(source != i)
            printf("%d->%d::%d\n", source, i, dist[i]);
    
    return 0;
}

void dijikstras(int cost[][100], int dist[], int n, int v) {
    int i, u = 0, w, count, min;
    int flag[100] = {0};
    
    for(i = 1; i <= n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }
    
    flag[v] = 1;
    dist[v] = 0;
    count = 2;
    
    while(count < n) {
        for(i = 1, min = INF; i <= n; i++) {
            if((dist[i] < min) && (flag[i] == 0)) {
                min = dist[i];
                u = i;
            }
        }
        flag[u] = 1;
        count++;
        
        for(w = 1; w <= n; w++) {
            if((dist[u] + cost[u][w] < dist[w]) && (flag[w] == 0))
                dist[w] = dist[u] + cost[u][w];
        }
    }
}

