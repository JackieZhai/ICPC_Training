/**
�㷨ģ�壺Ford-Fulkerson�㷨���ڽӱ�ʵ��
    ���Ӷȣ�O(F|E|)
*/
#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int MAX_V=1007;

//���ڱ�ʾ�ߵĽṹ��(�յ㡢�����������)
struct edge{
    int to, cap, rev;
};

vector<edge> G[MAX_V]; //ͼ���ڽӱ��ʾ
bool used[MAX_V]; //DFS���õ��ķ��ʱ��

//��ͼ������һ����s��t������Ϊcap�ı�
void add_edge(int from, int to, int cap)
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

//ͨ��DFSѰ������·
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

//����s��t�������
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
