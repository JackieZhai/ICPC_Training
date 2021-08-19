#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_V=1007, INF=0x3f3f3f3f;

struct edge {
	int to, cost;
};
typedef pair<int, int> P;//利用first表示最短距离，second表示顶点的编号 

int V;
vector<edge> G[MAX_V]; //下标充当from
int d[MAX_V];


void dijkstra(int s)
{
	//按照first从小到大顺序排列，先取出最短距离和对应的顶点 
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+V, INF);
	d[s]=0;
	que.push(P(0,s));
	
	while(que.size()) //复杂度为O(|E|Xlog|V|) 
	{
		P p = que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first)
			continue;
		for(int i=0; i<G[v].size(); i++)
		{
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}

int main()
{
	int E;
	scanf("%d%d", &E, &V);
	while(E--)
	{
		int f, t, dis;
		scanf("%d%d%d", &f, &t, &dis);
		f--, t--;
		G[f].push_back((edge){t, dis});
		G[t].push_back((edge){f, dis});
	}
	
	dijkstra(V-1);
	printf("%d\n", d[0]);
	
	
	
	
	return 0;
}
