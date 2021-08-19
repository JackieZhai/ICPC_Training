/*
练习题：Marked Ancestor_AOJ 2170
*/ 

#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100007;

//DUS start line

int par[MAX_N];//父亲 
int ran[MAX_N];//树的高度

//初始化n个元素
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		ran[i]=0;
	}
}

//查询树的根
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return find(par[x]);//此题这里不要给par[x]赋值，即不要做路径优化 
}

//合并x和y所属的集合
void unite(int x, int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return ;
	if(ran[x]<ran[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(ran[x]==ran[y])
			ran[x]++;
	}
}

//判断x和y是否属于同一个集合
bool same(int x, int y)
{
	return find(x)==find(y);
}

//DUS end line 

int N, Q;

int main()
{
	while(scanf("%d%d", &N, &Q)!=EOF)
	{
		if(N==0&&Q==0)
			break;
			
		memset(par, 0, sizeof(par));
		memset(ran, 0, sizeof(ran));
		par[1]=1;
		
		for(int i=2; i<=N; i++)
		{
			scanf("%d", &par[i]);
		}
		
		long long ans=0;
		for(int i=0; i<Q; i++)
		{
			char t;
			getchar();
			t=getchar();
			if(t=='Q')
			{
				int q;
				scanf("%d", &q);
				ans+=find(q);
			}
			else if(t=='M')
			{
				int m;
				scanf("%d", &m);
				par[m]=m;
			}
		}
		printf("%lld\n", ans);
		
		
	}
		
	
	return 0;
}


