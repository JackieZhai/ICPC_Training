#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 1007;
const int INF = 0x3f3f3f3f;

int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V;

void dijkstra(int s)
{
	fill(d, d+V, INF);
	fill(used, used+V, false);
	d[s]=0;
	
	while(true)
	{
		int v=-1;
		for(int u=0; u<V; u++)
		{
			if(!used[u] && (v==-1 || d[u]<d[v]))
				v=u;
		}
		if(v==-1)
			break;
		used[v]=true;
		for(int u=0; u<V; u++)
		{
			d[u]=min(d[u], d[v]+cost[v][u]);
		}
	}
}

int main()
{
	int E, S, D;
	while(scanf("%d%d%d", &E, &S, &D)!=EOF)
	{
		V=1007;
		memset(cost, INF, sizeof(cost));
		while(E--)
		{
			int f, t, c;
			scanf("%d%d%d", &f, &t, &c);
			if(cost[f][t]>c)
			{
				cost[f][t]=c;
				cost[t][f]=c;
			}
		}
		while(S--)
		{
			int t;
			scanf("%d", &t);
			cost[0][t]=0;
		}
		dijkstra(0);
		int ans=INF;
		while(D--)
		{
			int t;
			scanf("%d", &t);
			if(ans>d[t])
				ans=d[t];
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
