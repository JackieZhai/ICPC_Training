/*
��ϰ�⣺Silver Cow Party_POJ 3268
��������Dijkstra���ɡ� 
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V=1007;
const int INF=1000007;


struct edge {
	int to, cost;
};
typedef pair<int, int> P;//����first��ʾ��̾��룬second��ʾ����ı�� 

int V, E;
vector<edge> G[MAX_V]; //�±�䵱from
int d[MAX_V];

void dijkstra(int s)
{
	//����first��С����˳�����У���ȡ����̾���Ͷ�Ӧ�Ķ��� 
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d+1, d+V+1, INF);
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
	int g;
	scanf("%d%d%d", &V, &E, &g);
	for(int i=0; i<E; i++)
	{
		int f;
		edge ed;
		scanf("%d%d%d", &f, &ed.to, &ed.cost);
		G[f].push_back(ed);
	}
	int ans=0, sum=0;
	for(int i=1; i<=V; i++)
	{
		sum=0;
		dijkstra(i);
		sum+=d[g];
		dijkstra(g);
		sum+=d[i];
		if(ans<sum)
			ans=sum;
	}
	printf("%d\n", ans);
	
	return 0;
}



