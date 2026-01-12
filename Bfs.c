#include <stdio.h>
int n;
int adj[10][10]={0};
int visited[10]={0};
void bfs(int s){
    int queue[10];
    int rear=0,front=0;

    visited[s]=1;
    queue[rear++]=s;

    while(front<rear){
        int v=queue[front++];
        printf("%d ",v);
        for(int i=0;i<n;i++){
            if(adj[v][i]==1 && visited[i]==0){
                visited[i]=1;
                queue[rear++]=i;
            }
        }
    }
}
int main(){
    int u,v,e,s;

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
    printf("enter starting point");
    scanf("%d",&s);

    bfs(s);
   

}