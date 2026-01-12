#include <stdio.h>
#define INF 999

int main()
{
    int n;
    int cost[10][10];
    int visited[10]={0};
    int i,j;

    printf("enter no of vertices");
    scanf("%d",&n);

    printf("enter adj matrix");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0 && i!=j)
            {
                cost[i][j]=INF;
            }
        }
    }
    visited[0]=1;
    int edges=0,u=0,v=0,min=0,total=0;

    while (edges<n-1)
    {
        min=INF;
        for(i=0;i<n;i++)
        {
          if(visited[i]==1)
          {
            for(j=0;j<n;j++)
            {
                if(visited[j]==0 && cost[i][j]<min)
                {
                    min=cost[i][j];
                    u=i;
                    v=j;
                }
            }
          
          }
          

          
        
        }
        printf("%d-%d:%d",u,v,min);
        total+=min;
        visited[v]=1;
        edges++;
    }
    printf("total:%d",total);
    
}