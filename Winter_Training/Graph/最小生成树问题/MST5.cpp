/*
练习题：Bad Cowtractors_POJ 2377
	最“大”生成树。
	因为连不上要输出-1，所以用kruskal反而有点怪，需要检测一下是不是刚好是一个V个顶点的树。 
	（其实不用long long也可以AC） 
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_E=20007, MAX_V=1007;

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

int che=1;//检查是否全部连通在一棵树上 

long long kruskal()
{
	sort(es, es+E, cmp);
	
	init(V);
	

	long long res=0;
	for(int i=0; i<E; i++)
	{
		edge e=es[i];
		if(!same(e.u, e.v))
		{
			unite(e.u, e.v);
			res+=e.cost;
			che++;
		}
	}
	
	return res;
}

int main()
{
	scanf("%d%d", &V, &E);
	for(int i=0; i<E; i++)
	{
		edge ed;
		scanf("%d%d%d", &ed.u, &ed.v, &ed.cost);
		ed.cost=-ed.cost;
		es[i]=ed;
	}
	long long ans=-kruskal();
	if(che==V)
		printf("%lld\n", ans);
	else
		printf("-1\n");
	
	
	
	return 0;
}
