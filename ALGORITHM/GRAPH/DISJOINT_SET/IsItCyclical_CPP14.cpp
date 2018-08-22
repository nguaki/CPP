#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src;
    int des;
};

struct graph
{
    int v;
    int e;
    Edge *edge;
};

graph* creategraph(int v,int e)
{
    graph* g=new graph;
    g->v=v;
    g->e=e;
    g->edge= new Edge[e];

   return g;
};

int find (int parent[], int i)
{
    if(parent[i]==-1)
    return i;
    return find(parent,parent[i]);
}

void Union(int parent[], int x, int y)
{
  int xset = find(parent, x);
	int yset = find(parent, y);
	parent[xset] = yset;
}

int iscycle(graph* g)
{
int parent[g->v];
memset(parent,-1,sizeof(parent));
for(int i=0;i<g->e;i++)
{
    int x=find(parent,g->edge[i].src);
    int y=find(parent,g->edge[i].des);
    if(x==y)
    return 1;
    Union(parent,x,y);
}
return 0;
}

int main() 
{
    graph* g=creategraph(3,3);
    g->edge[0].src=0;
    g->edge[0].des=1;
    g->edge[1].src=1;
    g->edge[1].des=2;
    g->edge[2].src=2;
    g->edge[2].des=0;
    if(iscycle(g))
    cout<<"cycle exists:"<<endl;
    else
    cout<<"no cycle:";
    
    graph* f=creategraph(4,3);
    f->edge[0].src=0;
    f->edge[0].des=1;
    f->edge[1].src=1;
    f->edge[1].des=2;
    f->edge[2].src=2;
    f->edge[2].des=3;
    if(iscycle(f))
    cout<<"cycle exists:"<<endl;
    else
    cout<<"no cycle:";
    return 0;
}