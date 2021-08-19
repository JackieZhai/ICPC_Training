#include <bits/stdc++.h>
using namespace std;


const int MAX_V=;



//输入
vector<int> G[MAX_V];
int root;

int vs[MAX_V*2-1]; //DFS访问的顺序
int depth[MAX_V*2-1]; //节点的深度
int id[MAX_V]; //各个顶点在vs中首次出现的下标

void dfs(int v, int p, int d, int &k)
{
    id[v]=k;
    vs[k]=v;
    depth[k++]=d;
    for(int i=0; i<G[v].size(); i++)
    {
        if(G[v][i]!=p)
        {
            dfs(G[v][i], v, d+1, k);
            vs[k]=v;
            depth[k++]=d;
        }
    }
}

//预处理
void init(int V)
{
    //预处理出vs、depth、id
    int k=0;
    dfs(root, -1, 0, k);
    //预处理出RMQ(返回的不是最小值，而是最小值对应的下标)
    rmq_init(depth, V*2-1);
}

//计算u和v的LCA
int lca(int u, int v)
{
    return vs[query(min(id[u], id[v]), max(id[u], id[v])+1)];
}
