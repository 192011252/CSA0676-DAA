#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 1000
typedef struct
{
int u, v, w;
}
Edge;
int parent[MAX_VERTICES];
Edge edges[MAX_EDGES];
int find(int u) 
{
if (parent[u] == u) return u;
return parent[u] = find(parent[u]);
}
void union_sets(int u, int v) 
{
parent[find(u)] = find(v);
}
int cmp(const void* a, const void* b) 
{
Edge* ea = (Edge*)a;
Edge* eb = (Edge*)b;
return ea->w - eb->w;
}
int main() 
{
int n, m, u, v, w;
scanf("%d %d", &n, &m);
for (int i = 0; i < m; i++)
{
scanf("%d %d %d", &u, &v, &w);
edges[i] = (Edge){u, v, w};
}
qsort(edges, m, sizeof(Edge), cmp);
for (int i = 0; i < n; i++)
{
parent[i] = i;
}
int mst_weight = 0;
for (int i = 0; i < m; i++) 
{
Edge e = edges[i];
if (find(e.u) != find(e.v)) 
{
union_sets(e.u, e.v);
mst_weight += e.w;
}
}
printf("%d\n", mst_weight);
return 0;
}
