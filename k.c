#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int parent[10];

// Find set (with path compression)
int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

// Union two sets
void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}

// Sort edges by weight (Bubble sort for simplicity)
void sortEdges(struct Edge edges[], int e) {
    struct Edge temp;
    for(int i = 0; i < e-1; i++) {
        for(int j = 0; j < e-i-1; j++) {
            if(edges[j].w > edges[j+1].w) {
                temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, e;
    struct Edge edges[20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize parent
    for(int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    sortEdges(edges, e);

    int count = 0;
    int total = 0;

    printf("\nEdges in MST:\n");

    for(int i = 0; i < e && count < n-1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if(find(u) != find(v)) {
            printf("%d - %d : %d\n", u, v, w);
            total += w;
            unite(u, v);
            count++;
        }
    }

    printf("Total cost = %d\n", total);
    return 0;
}
