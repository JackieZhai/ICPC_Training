#include <bits/stdc++.h>
using namespace std;

const int MAX_V=507, INF=0x3f3f3f3f;

int cost[MAX_V][MAX_V];
int previ[MAX_V];
int d[MAX_V];
int dcount[MAX_V];
int team[MAX_V];
bool used[MAX_V];
int save[MAX_V];
int V,E;
int st, en;

void dijkstra(int s)
{
	fill(d, d+V, INF);
	fill(used, used+V, false);
	fill(previ, previ+V, -1);
	d[s]=0;
	team[s]=save[s];
	dcount[s]=1;
	
	while(true)
	{
		int v=-1;
		for(int u=0; u<V; u++)
		{
			if(!used[u]&&(v==-1||d[u]<d[v]))
			{
				v=u;
			}
		}
		
		if(v==-1)
			break;
		used[v]=true;
		
		for(int u=0; u<V; u++)
		{
			if(d[u]>d[v]+cost[v][u])
			{
				d[u]=d[v]+cost[v][u];
				dcount[u]=dcount[v];
				team[u]=team[v]+save[u];
				previ[u]=v;
			}
			else if(d[u]==d[v]+cost[v][u])
			{
				dcount[u]=dcount[u]+dcount[v];
				if(team[u]<team[v]+save[u])
				{
					team[u]=team[v]+save[u];
					previ[u]=v;
				}
			}
		}
	}
}

vector<int> get_path(int t)
{
	vector<int> path;
	for( ; t!=-1; t=previ[t])
		path.push_back(t);
	reverse(path.begin(), path.end());
	return path;
}

int main()
{
	scanf("%d%d%d%d", &V, &E, &st, &en);
	for(int i=0; i<V; i++)
	{
		scanf("%d", &save[i]);
	}
	
	memset(cost, INF, sizeof(cost));
	
	for(int i=0; i<E; i++)
	{
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		cost[u][v]=c;
		cost[v][u]=c;
	}
	
	dijkstra(st);
	
	vector<int> path=get_path(en);
	
	printf("%d %d\n", dcount[en], team[en]);
	
	for(int i=0; i<path.size(); i++)
	{
		if(i!=0)
			printf(" ");
		printf("%d", path[i]);
	}
	printf("\n");
	
	
	
	return 0;
}
