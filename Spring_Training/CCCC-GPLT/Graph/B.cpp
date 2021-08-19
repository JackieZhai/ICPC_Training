#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1007;
const int INF=0x3f3f3f3f;

int g[maxn][maxn],d[maxn];
int cost[maxn][maxn];
int co[maxn];
int n,m,s;
bool v[maxn];

void dijkstra(int s)
{
    memset(v,0,sizeof v);
    
    for(int i = 0; i <= n; ++i)
		d[i] = (i == s ? 0 : INF), co[i] = INF;
    
	co[s] = d[s] = 0;
    
	for (int i = 0; i <= n; ++i)
	{
        int x,m = INF;
        for (int y = 0; y <= n; ++y) 
			if (!v[y] && d[y] <= m)
				m = d[x=y];
        v[x] = 1;
        for (int y = 0; y <= n; ++y)
		{
            if (d[y] > d[x] + g[x][y])
			{
                d[y]= d[x]+g[x][y];
                co[y] = co[x] + cost[x][y];
            }
            else if (d[y] == d[x] + g[x][y] && co[y] > co[x] + cost[x][y])
			{
                co[y] = co[x] + cost[x][y];
            }
        }
    }
}


int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)
			break;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                g[i][j] = INF,cost[i][j] = INF;
        for (int i = 0; i < m; ++i)
		{
            int u,v,w,x;
            scanf("%d%d%d%d",&u,&v,&w,&x);
            if (g[u][v] > w)
			{
                g[u][v] = g[v][u] = w;
                cost[u][v] = cost[v][u] = x;
            }
			else if (g[u][v] == w && cost[u][v] < x)
			{
                cost[u][v] = cost[v][u] = x;
            }
        }
        
        int s,e;
        scanf("%d%d",&s,&e);
        dijkstra(s);
        printf("%d %d\n",d[e],co[e]);
    }

    return 0;
}


