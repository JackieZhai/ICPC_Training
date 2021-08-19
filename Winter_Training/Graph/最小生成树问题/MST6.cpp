/*
练习题：Save your cats_AOJ 2224 
	减去最少、小的边，使得整个平面连通；
	即为求最大生成树问题，但注意求的是裁去的路径。
	另外，此题的坐标转化也需要注意(在不超范围的情况下尽可能最后再开方) 
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_E=49995007, MAX_V=10007;
int mark[MAX_E];
pair<int, int> ver[MAX_V];

struct edge{
	int u, v, cost;
}; 
bool cmp(const edge& e1, const edge& e2)
{
	return e1.cost<e2.cost;
}

edge es[MAX_E];
int V, E;


//DUS start line

int par[MAX_V];//父亲 
int hight[MAX_V];//树的高度

//初始化n个元素
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		hight[i]=0;
	}
}

//查询树的根
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
}

//合并x和y所属的集合
void unite(int x, int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return ;
	if(hight[x]<hight[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(hight[x]==hight[y])
			hight[x]++;
	}
}

//判断x和y是否属于同一个集合
bool same(int x, int y)
{
	return find(x)==find(y);
}

//DUS end line 


double kruskal()
{
	sort(es, es+E, cmp);
	
	init(V);
	

	double res=0;
	for(int i=0; i<E; i++)
	{
		edge e=es[i];
		if(!same(e.u, e.v))
		{
			unite(e.u, e.v);
			mark[i]=1;
		}
	}
	
	for(int i=0; i<E; i++)
	{
		if(mark[i]==0)
			res+=sqrt(-es[i].cost);
	}
	return res;
}

int main()
{
	scanf("%d%d", &V, &E);
	for(int i=0;  i<V; i++)
	{
		scanf("%d%d", &ver[i].first, &ver[i].second);
	}
	for(int i=0; i<E; i++)
	{
		edge ed;
		scanf("%d%d", &ed.u, &ed.v);
		ed.u--;
		ed.v--;
		ed.cost=-((ver[ed.u].first-ver[ed.v].first)*(ver[ed.u].first-ver[ed.v].first)+(ver[ed.u].second-ver[ed.v].second)*(ver[ed.u].second-ver[ed.v].second));
		es[i]=ed;
	}
	
	double ans=kruskal();
	printf("%.3lf\n", ans);
	
	
	return 0;
}
