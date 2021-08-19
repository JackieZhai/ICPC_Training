/**
���⣺Intervals_POJ 3680
    ����Ȩ�߽���Ԥ����
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_V=100007;
const int INF=0x3f3f3f3f;
typedef pair<int, int> P; //first������̾��룬second���涥����

// ���ڱ�ʾ�ߵĽṹ��(�յ㡢���������á������)
struct edge{
    int to, cap, cost, rev;
};

int V;
vector<edge> G[MAX_V];
int h[MAX_V]; //�������
int dist[MAX_V]; //��̾���
int prevv[MAX_V], preve[MAX_V]; //���·�е�ǰ���ڵ�Ͷ�Ӧ�ı�
//��ͼ������һ����from��to����Ϊcap����Ϊcost�ı�

void add_edge(int from, int to, int cap, int cost)
{
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size()-1});
}

//����s��t����С������
//���û������Ϊf�������򷵻�-1
int min_cost_flow(int s, int t, int f)
{
    int res=0;
    fill(h, h+V, 0);
    while(f>0)
    {
        //ʹ��Dijkstra�㷨����h
        priority_queue<P, vector<P>, greater<P> > que;
        fill(dist, dist+V, INF);
        dist[s]=0;
        que.push(P(0, s));
        while(!que.empty())
        {
            P p=que.top();
            que.pop();
            int v=p.second;
            if(dist[v]<p.first)
                continue;
            for(int i=0; i<G[v].size(); i++)
            {
                edge &e=G[v][i];
                if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
                {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
        if(dist[t]==INF)
        {
            //����������
            return -1;
        }
        for(int v=0; v<V; v++)
            h[v]+=dist[v];

        //��s��t�����·��������
        int d=f;
        for(int v=t; v!=s; v=prevv[v])
        {
            d=min(d, G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t; v!=s; v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}

const int MAX_N=207;
int N, K;
int a[MAX_N], b[MAX_N], w[MAX_N];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++)
        {
            scanf("%d%d%d", &a[i], &b[i], &w[i]);
        }

        //Ԥ����˵㼯��
        vector<int> x;
        for(int i=0; i<N; i++)
        {
            x.push_back(a[i]);
            x.push_back(b[i]);
        }
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());

        //��ͼ
        int m=x.size();
        int s=m, t=s+1;
        V=t+1;
        int res=0;
        for(int i=0; i<V; i++) //���������ͼ
            G[i].clear();
        add_edge(s, 0, K, 0);
        add_edge(m-1, t, K, 0);
        for(int i=0; i+1<m; i++)
            add_edge(i, i+1, INF, 0);
        for(int i=0; i<N; i++)
        {
            int u=find(x.begin(), x.end(), a[i])-x.begin();
            int v=find(x.begin(), x.end(), b[i])-x.begin();
            //��u��v��һ������Ϊ1������Ϊ-w[i]�ı�
            add_edge(v, u, 1, w[i]);
            add_edge(s, v, 1, 0);
            add_edge(u, t, 1, 0);
            res-=w[i];
        }

        res+=min_cost_flow(s, t, K+N);
        printf("%d\n", -res);
    }




    return 0;
}

