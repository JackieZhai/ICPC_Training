/**
例题：Popular Cows_POJ 2186

*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V=10007;

int V; //顶点数
vector<int> G[MAX_V]; //图的邻接表示
vector<int> rG[MAX_V]; //把边反向后的图
vector<int> vs; //后序遍历顺序的顶点列表
bool used[MAX_V]; //访问标记
int cmp[MAX_V]; //所属强联通分量的拓扑序

void add_edge(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v)
{
    used[v]=true;
    for(int i=0; i<G[v].size(); i++)
        if(!used[G[v][i]])
            dfs(G[v][i]);
    vs.push_back(v);
}

void rdfs(int v, int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0; i<rG[v].size(); i++)
        if(!used[rG[v][i]])
            rdfs(rG[v][i], k);
}

int scc()
{
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v=0; v<V; v++)
        if(!used[v])
            dfs(v);
    memset(used, 0, sizeof(used));
    int k=0;
    for(int i=vs.size()-1; i>=0;  i--)
        if(!used[vs[i]])
            rdfs(vs[i], k++);
    return k; //代表共有几个强连通分量
}

const int MAX_M=50007;
//输入
int N, M;
int A[MAX_M], B[MAX_M];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
    {
        scanf("%d%d", &A[i], &B[i]);
    }
    V=N;
    for(int i=0; i<M; i++)
    {
        add_edge(A[i]-1, B[i]-1);
    }
    int n=scc();

    //最后分量的个数
    int u=0, num=0;
    for(int v=0; v<V; v++)
    {
        if(cmp[v]==n-1)
        {
            u=v;
            num++;
        }
    }

    //判联通
    memset(used, 0, sizeof(used));
    rdfs(u, 0); //复用代码，k在这里无意义
    for(int v=0; v<V;  v++)
        if(!used[v])
        {
            //不可达
            num=0;
            break;
        }

    printf("%d\n", num);

    return 0;
}
