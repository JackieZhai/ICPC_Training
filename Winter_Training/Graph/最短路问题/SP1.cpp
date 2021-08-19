/*
单源最短路问题(Bellman-Ford Algorithm)：
	单源最短路是固定一个起点，求它到其他所有点之间的距离的最短路。(和两点间最短路问题复杂度一样) 
	常用于求解有负边的情况。 
*/ 
#include <bits/stdc++.h>
using namespace std;

struct edge{
	int from, to, cost;
}es[MAX_E];

int d[MAX_V]; //最短距离
int V, E;

void shortest_path(int s)
{
	for(int i=0; i<V; i++)
		d[i]=INF;
	d[s]=0;
	while(true) //如果不存在负圈，复杂度是O(|V|X|E|) 
	{
		bool update=false;
		for(int i=0; i<E; i++)
		{
			edge e=es[i];
			if(d[e.from!=INF && d[e.to]>d[e.from]+e.cost])
			{
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(!update)
			break;
	}
}
