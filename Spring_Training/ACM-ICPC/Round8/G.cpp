#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f;
const int MAX_V=1007;

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

int m, n;
int used[1007];
int cus[107];


int main()
{
    scanf("%d%d", &m, &n);
    for(int i=1; i<=m; i++)
    {
        int buf;
        scanf("%d", &buf);
        add_edge(n+i, n+m+1, buf);
    }
    for(int i=1; i<=n; i++)
    {
        int c;
        scanf("%d", &c);
        for(int j=1; j<=c; j++)
        {
            int buf;
            scanf("%d", &buf);
            if(used[buf]!=0)
            {
                add_edge(i, used[buf], INF);
            }
            else
            {
                add_edge(i, n+buf, INF);
            }
            used[buf]=i;
        }
        int b;
        scanf("%d", &b);
        add_edge(0, i, b);


    }

    printf("%d\n", max_flow(0, n+m+1));



    return 0;
}













/*

8 14
0 1 2
0 2 3
0 3 6
1 4 999999
1 5 999999
2 4 999999
2 6 999999
3 5 999999
3 1 999999
3 1 999999
2 1 999999
4 7 3
5 7 1
6 7 10

*/
