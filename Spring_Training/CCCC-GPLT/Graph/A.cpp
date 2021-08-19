#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX_V=1007, INF=0x3f3f3f3f;

struct edge {
	int to, cost;
};
typedef pair<int, int> P;//����first��ʾ��̾��룬second��ʾ����ı�� 

int V;
vector<edge> G[MAX_V]; //�±�䵱from
int d[MAX_V];


void dijkstra(int s)
{
	//����first��С����˳�����У���ȡ����̾���Ͷ�Ӧ�Ķ��� 
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+V, INF);
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
	scanf("%d%d", &E, &V);
	while(E--)
	{
		int f, t, dis;
		scanf("%d%d%d", &f, &t, &dis);
		f--, t--;
		G[f].push_back((edge){t, dis});
		G[t].push_back((edge){f, dis});
	}
	
	dijkstra(V-1);
	printf("%d\n", d[0]);
	
	
	
	
	return 0;
}
