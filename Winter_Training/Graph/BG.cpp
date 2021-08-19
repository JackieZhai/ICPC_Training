/*
二分图判定：
定义：1、没有奇数边回路；
	  2、分为两部分，其公共部分没有边。
相关：着色问题；
	  二分图匹配（匈牙利算法等）。 
*/ 
#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1000;

vector<int> G[MAX_V]; //图的邻接表实现：下标为始边，值是终边
int V, E;
int color[MAX_V];
	
bool dfs(int v, int c)
{
	color[v]=c;
	for(int i=0; i<G[v].size(); i++)//遍历相邻结点 
	{
		if(color[G[v][i]]==c)
			return false;
		if(color[G[v][i]]==0 && !dfs(G[v][i], -c))
			return false;//false的传递进行剪枝 
	}
	return true;//所有边都已经染过色了 
}

void solve()
{
	for(int i=0; i<V; i++)
	{
		if(color[i]==0)
		{
			if(!dfs(i, 1))//将顶点染成1色，其相邻顶点染成-1色
			{
				printf("NO\n");
				return ;
			}
		}
	}
	printf("YES\n");
}

int main()
{
	scanf("%d%d", &V, &E);
	for(int i=0; i<E; i++)
	{
		int s, t;
		scanf("%d%d", &s, &t);
		G[s].push_back(t);
		G[t].push_back(s);//无向图两边的联系都要建立	
	}
	 
	solve(); 
	
	return 0;
}
