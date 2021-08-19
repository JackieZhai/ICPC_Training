/*
��ϰ�⣺Convenient Location_AOJ 0189 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V=17, INF=0x3f3f3f3f;

struct edge {
	int to, cost;
};
typedef pair<int, int> P;//����first��ʾ��̾��룬second��ʾ����ı�� 

vector<edge> G[MAX_V]; //�±�䵱from
int d[MAX_V];
int sum[MAX_V];

void dijkstra(int s)
{
	//����first��С����˳�����У���ȡ����̾���Ͷ�Ӧ�Ķ��� 
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+10, INF);
	d[s]=0;
	que.push(P(0,s));
	
	while(que.size()) //���Ӷ�ΪO(|E|Xlog|V|) 
	{
		P p = que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first)
			continue;
		for(int i=0; i<G[v].size(); i++)
		{
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}



int main()
{
	int E;
	while(scanf("%d", &E)!=EOF)
	{
		if(E==0)
			break;
		
		memset(sum, 0, sizeof(sum));
		for(int i=0; i<10; i++)
			G[i].clear();
		
		for(int i=0; i<E; i++)
		{
			int f,t,c;
			scanf("%d%d%d", &f, &t, &c);
			G[f].push_back((edge){t,c});
			G[t].push_back((edge){f,c});
		}
		
		for(int i=0; i<10; i++)
		{
			dijkstra(i);
			for(int j=0; j<10; j++)
			{
				if(d[j]!=INF)
					sum[i]+=d[j];
			}
		}
		
		int ans1, ans2=0x3f3f3f3f;
		for(int i=0; i<10; i++)
		{
			if(sum[i]!=0&&ans2>sum[i])
			{
				ans2=sum[i];
				ans1=i;
			}
		}
		
		printf("%d %d\n", ans1, ans2);
		
		
	}
	
	return 0;
}
