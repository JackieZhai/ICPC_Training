/*
练习题：Find them, Catch them_POJ 1703 
*/
#include<cstdio>
using namespace std;

const int MAX_N=200005;

//DUS start line

int par[MAX_N];//父亲 
int rank[MAX_N];//树的高度

//初始化n个元素
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		rank[i]=0;
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
	if(rank[x]<rank[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
}

//判断x和y是否属于同一个集合
bool same(int x, int y)
{
	return find(x)==find(y);
}

//DUS end line 

int N, M;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &M);
		
		//设置第x个为x-Dragon，第x+N个为x-Snake 
		init(2*N);
		
		char buf;
		while(M--)
		{
			getchar();
			buf=getchar();
			if(buf=='D')
			{
				int q1,q2;
				scanf("%d%d", &q1, &q2);
				unite(q1, q2+N);
				unite(q2, q1+N);
			}
			else if(buf=='A')
			{
				int q1,q2;
				scanf("%d%d", &q1, &q2);
				if(same(q1, q2+N)&&same(q1+N, q2))
				{
					printf("In different gangs.\n");
				}
				else if(same(q1, q2)&&same(q1+N, q2+N))
				{
					printf("In the same gang.\n");
				}
				else
				{
					printf("Not sure yet.\n");
				}
			}
			
		}
	}
	return 0;
}





















