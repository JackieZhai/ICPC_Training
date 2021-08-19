#include <bits/stdc++.h>
using namespace std;


//-----最大流-----
const int INF=0x3f3f3f3f;
const int MAX_V=107*107*2;
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
//-----最大流-----


//-----埃氏筛法-----
const int MAX_N=100007;

int prime[MAX_N]; //第i个素数，此为存放素数的数组
bool is_prime[MAX_N]; //is_prime[]为true时为素数
//返回n以内素数的个数
int sieveErato(int n)
{
	int p=0;
	for(int i=0; i<=n; i++)
		is_prime[i]=true;
	is_prime[0]=false;
	is_prime[1]=false;
	for(int i=2; i<=n; i++)
	{
		if(is_prime[i])
		{
			prime[p++]=i;
			for(int j=2*i; j<=n; j+=i)
				is_prime[j]=false;
		}
	}
	return p;
}
//-----埃氏筛法-----


int n, m;
int a[107];
int x[107], y[107];

int main()
{
    int k=sieveErato(MAX_N);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        if(y[i]%2==1)
            swap(x[i], y[i]);
    }








    return 0;
}
