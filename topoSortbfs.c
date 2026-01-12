#include <stdio.h>
#define MAX 10

int n;
int adj[MAX][MAX] = {0};
int indegree[MAX] = {0};

void topoBFS()
{
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX], k = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    for(int i = 0; i < n; i++){
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    while(front < rear){
        int v = queue[front++];
        topo[k++] = v;

        for(int i = 0; i < n; i++){
            if(adj[v][i] == 1){
                indegree[i]--;
                if(indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }


    printf("Topological Order: ");
    for(int i = 0; i < k; i++)
        printf("%d ", topo[i]);
}

int main()
{
    int e, u, v;

    printf("Enter no of vertices: ");
    scanf("%d", &n);

    printf("Enter no of edges: ");
    scanf("%d", &e);

    printf("Enter directed edges (u v):\n");
    for(int i = 0; i < e; i++){
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;   // directed
    }

    topoBFS();
    return 0;
}
