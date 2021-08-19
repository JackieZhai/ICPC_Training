/*
例题：Conscription_POJ 3723 
	此题就是求解最大权森林问题，可以把所有边权取反后用最小生成树的算法求解。
注：貌似男女直接有区别，但是此题并没有影响，是未用到男女之间二分图的陷阱题目。 
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_V=20007, MAX_E=50007;

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


int kruskal()
{
	sort(es, es+E, cmp);
	
	init(V);
	
	int res=0;
	for(int i=0; i<E; i++)
	{
		edge e=es[i];
		if(!same(e.u, e.v))
		{
			unite(e.u, e.v);
			res+=e.cost;
		}
	}
	
	return res;
}

int N, M, R;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d%d", &N, &M, &R);
		V=N+M;
		E=R;
		for(int i=0; i<R; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			es[i]=(edge){a, N+b, -c};
		}
		
		printf("%d\n", 10000*V+kruskal());
		
	}
		
	return 0;
}

