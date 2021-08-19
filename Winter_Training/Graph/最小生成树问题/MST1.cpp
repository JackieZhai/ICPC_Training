/*
最小生成树(Minimum Spanning Tree)问题(Prim Algorithm)：
	Prim和Dijkstra很类似，都是从顶点出发不断加边的过程(直到顶点集合的数量X==V)；
	查找最小权值的边mincost[]同Dijkstra一样用优先队列维护。 
*/
#include <bits/stdc++.h>
using namespace std;

int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;

int prim()
{
	for(int i=0; i<V; i++)
	{
		mincost[i]=INF;
		used[i]=false;
	}
	mincost[0]=0;
	int res=0;
	
	while(true)
	{
		int v=-1;
		//从不属于X的顶点中选取从X到其权值最小的顶点
		for(int u=0; u<V; u++)
		{
			if(!used[u] && (v==-1||mincost[u]<mincost[v]))
				v=u;
		}
		
		if(v==-1)
			break;
		used[v]=true; //把顶点v加入X 
		res+=mincost[v]; //把边的长度加入到结果里 
		
		
		//此处可以使用堆来维护，降低时间复杂度 
		for(int u=0; u<V; u++)
		{
			mincost[u]=min(mincost[u], cost[v][u]);
		}
	}
	
	return res;
}

