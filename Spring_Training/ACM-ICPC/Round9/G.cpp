#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


const int INF=0x3f3f3f3f;
const int MAX_V=207;
//用于表示边的结构体(终点、容量、反向边)
struct edge{
    int to, cap, rev;
};
vector<edge> G[MAX_V]; //图的邻接表表示
int level[MAX_V]; //顶点到源点的距离标号
int iter[MAX_V]; //当前弧，在其之前的边已经没有用了
//向图中增加一条从s到t的容量为cap的边
void add_edge(int from, int to, int cap)
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}
//通过BFS计算从源点出发的距离标号
void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(int i=0; i<G[v].size(); i++)
        {
            edge &e=G[v][i];
            if(e.cap>0 && level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
//通过DFS寻找增广路
int dfs(int v, int t, int f)
{
    if(v==t)
        return f;
    for(int &i=iter[v];  i<G[v].size(); i++)
    {
        edge &e=G[v][i];
        if(e.cap>0 && level[v]<level[e.to])
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
        bfs(s);
        if(level[t]<0)
            return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f=dfs(s, t, INF))>0)
            flow+=f;
    }
}



int n, m;



int main()
{
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        for(int i=1; i<=m; i++)
            G[i].clear();
        memset(level, 0, sizeof(level));
        memset(iter, 0, sizeof(iter));

        for(int i=1; i<=n; i++)
        {
            int f, t, c;
            scanf("%d%d%d", &f, &t, &c);
            add_edge(f, t, c);
        }

        printf("%d\n", max_flow(1, m));

    }


    return 0;
}
