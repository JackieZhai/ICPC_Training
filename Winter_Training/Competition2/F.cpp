/*
	TLE in test 10:
	使用find()强行降低复杂度；
	另外t[]和sum可能有的test会有小淘气，需要设计成long long防止WA。 
*/


#include <bits/stdc++.h>
using namespace std;


const int MAX_N=150005, MAX_M=150005;
//int mark[MAX_N];
long long t[MAX_N];

//DUS start line

int par[MAX_N];//父亲 
int rankd[MAX_N];//树的高度

//初始化n个元素
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		rankd[i]=0;
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
	if(rankd[x]<rankd[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(rankd[x]==rankd[y])
			rankd[x]++;
	}
}

//判断x和y是否属于同一个集合
bool same(int x, int y)
{
	return find(x)==find(y);
}

//DUS end line 


int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	
	init(N+1);
	
	//memset(mark, 1, sizeof(mark));
	
	for(int i=0; i<M; i++)
	{
		int q1, q2;
		scanf("%d%d", &q1, &q2);
		unite(q1, q2);
	//	mark[q1]=0;
	//	mark[q2]=0;
	}
	
	
//	int sum=0, count=1;
//	for(int i=1; i<=N; i++)
//	{
//		if(mark[i]==1)
//			continue;
//		
//		for(int j=i+1; j<=N; j++)
//		{	
//			if(mark[j]==1)
//				continue;
//			if(same(j, i))
//			{
//				count++;
//				mark[j]=1;
//			}
//		}
//		sum+=count*(count-1)/2;
//		count=1;
//	}
//以下为改进代码：(利用find()函数，不需要嵌套循环就可以计算块的元素数，复杂度变为O(N)。） 
	for(int i=1; i<=N; i++)
	{  
        t[find(i)]++;  
    }  
    long long sum=0;  
    for(int i=1; i<=N; i++)
	{  
        if(t[i]!=0&&t[i]!=1)
		{  
            sum+=(t[i]*(t[i]-1)/2);  
        }  
    }
	
	
	if(sum==M)
		printf("YES\n");
	else
		printf("NO\n");
	

	return 0;
}
