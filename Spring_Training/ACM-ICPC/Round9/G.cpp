#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


const int INF=0x3f3f3f3f;
const int MAX_V=207;
//���ڱ�ʾ�ߵĽṹ��(�յ㡢�����������)
struct edge{
    int to, cap, rev;
};
vector<edge> G[MAX_V]; //ͼ���ڽӱ��ʾ
int level[MAX_V]; //���㵽Դ��ľ�����
int iter[MAX_V]; //��ǰ��������֮ǰ�ı��Ѿ�û������
//��ͼ������һ����s��t������Ϊcap�ı�
void add_edge(int from, int to, int cap)
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}
//ͨ��BFS�����Դ������ľ�����
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
//ͨ��DFSѰ������·
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
//����s��t�������
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
