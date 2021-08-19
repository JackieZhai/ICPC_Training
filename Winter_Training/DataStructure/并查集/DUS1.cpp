/*
例题：食物链_POJ 1182 

并查集里面的每一个组内元素都是同时发生或者同时不发生；
把x-A和x-B和x-C记为x, x+N, x+2*N。 
*/
#include<cstdio>
using namespace std;

const int MAX_N=150005, MAX_K=100005;

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

int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];

void solve()
{
	//初始化并查集 
	//元素x, x+N, x+2*N分别代表x-A, x-B, x-C
	init(N*3);
	
	int ans=0;
	for(int i=0; i<K; i++)
	{
		int t=T[i];
		int x=X[i]-1, y=Y[i]-1;//把输入变为0~N-1的范围
		
		//不正确的编号 
		if(x<0||N<=x||y<0||N<=y)
		{
			ans++;
			continue;
		}
		
		if(t==1)
		{
			//“x和y属于同一类”的信息 
			if(same(x, y+N)||same(x, y+2*N))
			{
				ans++;
			}
			else
			{
				unite(x,y);
				unite(x+N,y+N);
				unite(x+N*2,y+N*2);
			}
		}
		else
		{
			//“x吃y”的信息
			if(same(x,y)||same(x,y+2*N))
			{
				ans++;
			}
			else
			{
				unite(x,y+N);
				unite(x+N,y+2*N);
				unite(x+2*N,y);
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0; i<K; i++)
		scanf("%d%d%d", &T[i], &X[i], &Y[i]);
	
	solve();
	
	return 0;
} 
