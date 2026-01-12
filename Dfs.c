#include <stdio.h>

int n;
int visited[10]={0};
int adj[10][10]={0};

void dfs(int v){
    visited[v]=1;
    printf("%d ",v);
    for(int i=0;i<n;i++){
        if(adj[v][i]==1&&visited[i]==0){
            dfs(i);
        }
    }
}

int main(){
    int v,u,e,s;

    printf("enter no of vertices:");
    scanf("%d",&n);

    printf("enter no of edges:");
    scanf("%d",&e);

    printf("enter edges:");
    for(int i=0;i<e;i++){
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        adj[v][u]=1;
    }
    printf("enter starting point:");
    scanf("%d",&s);

    dfs(s);

}