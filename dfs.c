#include <stdio.h>
#define max 10

int n;
int adj[max][max];
int visited[max];
 
void dfs(int v){
    visited[v]=1;
    printf("%d",v);

    for( int i=0;i<n;i++){
        if(adj[v][i]==1 && visited[i]==0){
            dfs(i);
        }
    }
}

int main(){
    int edges,start,u,v,i,j;

    printf("enter no of vertices");
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        visited[i]=0;
        for(j=0;j<n;j++){
            adj[i][j]=0;
        }
    }

    printf("enter no of edges");
    scanf("%d",&edges);

    printf("Enter edges \n");
    for(i=0;i<edges;i++){
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    printf("enter starting vertex");
    scanf("%d",&start);

    dfs(start);
    

}