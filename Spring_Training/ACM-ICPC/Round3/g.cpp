#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_V=10007;
const int INF=0x3f3f3f3f;
int V;

struct edge{int to, cap, rev;};

vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap)
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

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

int dfs(int v, int t, int f)
{
    if(v==t)
        return f;
    for(int &i=iter[v]; i<G[v].size(); i++)
    {
        edge &e=G[v][i];
        if(e.cap>0 && level[v]<level[e.to])
        {
            int d=dfs(e.to, t, min(f, e.cap));
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



int main()
{
    scanf("%d", &V);
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++)
        {
            int buf;
            scanf("%d", &buf);

            if(i>j)
            {
                add_edge(i, j, buf);
                add_edge(j, i, buf);
            }
        }
    }

    int ans=0;
    for(int i=0; i<V; i++)
        for(int j=i+1; j<V; j++)
        {
            int m=max_flow(i, j);
            if(ans<m)
                ans=m;
        }

    printf("%d\n", ans);




    return 0;
}
