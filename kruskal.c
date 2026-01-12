#include <stdio.h>

struct edge{
    int u,v,w;
};

int parent[100];

int find(int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

void unite(int a,int b){
    int rootA=find(a);
    int rootB=find(b);
    parent[rootA]=rootB;
}

void sortedges(struct edge edges[],int e){
    struct edge temp;
    for(int i=0;i<e-1;i++){
        for(int j=0;j<e-i-1;j++){
            if(edges[j].w>edges[j+1].w){
                temp=edges[j];
                edges[j]=edges[j+1];
                edges[j+1]=temp;
            }
        }
    }
}
int main(){
    int n,e;
    struct edge edges[20];

    printf("enter no of vertices:");
    scanf("%d",&n);
    printf("enter no of edges:");
    scanf("%d",&e);
    printf("enter edges:");
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);
    }

    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    sortedges(edges,e);

    int count=0,total=0;
    
    printf("\nEdges in MST:\n");

    for(int i=0;i<e&&count<n-1;i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;

        if(find(u)!=find(v)){
            printf("%d-%d:%d\n",u,v,w);
            unite(u,v);
            total+=w;
            count++;
        }
    }
    
    printf("Total cost=%d",total);

}