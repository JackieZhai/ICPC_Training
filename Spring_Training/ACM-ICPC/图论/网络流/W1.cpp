/**
算法模板：Ford-Fulkerson算法的邻接表实现
    复杂度：O(F|E|)
*/
#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int MAX_V=1007;

//用于表示边的结构体(终点、容量、反向边)
struct edge{
    int to, cap, rev;
};

vector<edge> G[MAX_V]; //图的邻接表表示
bool used[MAX_V]; //DFS中用到的访问标记

//向图中增加一条从s到t的容量为cap的边
void add_edge(int from, int to, int cap)
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

//通过DFS寻找增广路
int dfs(int v, int t, int f)
{
    if(v==t)
        return f;
    used[v]=true;
    for(int i=0;  i<G[v].size(); i++)
    {
        edge &e=G[v][i];
        if(!used[e.to] && e.cap>0)
        {
            int  d=dfs(e.to, t, min(f, e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

//求解从s到t的最大流
int max_flow(int s, int t)
{
    int flow=0;
    while(true)
    {
        memset(used, 0, sizeof(used));
        int f=dfs(s, t, INF);
        if(f==0)
            return flow;
        flow+=f;
    }
}



int main()
{
    int V, E;
    scanf("%d%d", &V, &E);
    while(E--)
    {
        int f, t, c;
        scanf("%d%d%d", &f, &t, &c);
        add_edge(f, t, c);
    }
    printf("%d\n", max_flow(0, V-1));



    return 0;
}
