/*
��Դ���·����(Dijkstra Algorithm)��

���⣺Roadlocks_POJ 3255
	�ζ�·���⡣ 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N=50005;
const int INF=100005;

struct edge{
	int to, cost;
};
typedef pair<int, int> P;//����first��ʾ��̾��룬second��ʾ����ı�� 

int N, R;//NΪ���㣬RΪ��
vector<edge> G[MAX_N];

int dist[MAX_N];
int dist2[MAX_N];

void solve()
{
	priority_queue<P, vector<P>, greater<P> > que;
	fill(dist, dist+N, INF);
	fill(dist2, dist2+N, INF);
	dist[0]=0;
	que.push(P(0,0));
	
	while(que.size())
	{
		P p = que.top();
		que.pop();
		int v=p.second, d=p.first;
		if(dist2[v]<d)
			continue;
		for(int i=0; i<G[v].size(); i++)
		{
			edge &e = G[v][i];
			int d2=d+e.cost;
			if(dist[e.to]>d2)
			{
				swap(dist[e.to], d2); //����d2��dist2[]�����ж� 
				que.push(P(dist[e.to], e.to));
			}
			if(dist2[e.to]>d2 && dist[e.to]<d2)
			{
				dist2[e.to]=d2;
				que.push(P(dist2[e.to], e.to));
			}
		}
		
	}
	
	printf("%d\n", dist2[N-1]);
}


int main()
{
	scanf("%d%d", &N, &R);
	for(int i=0; i<R; i++)
	{
		int f;
		edge ebuf1;
		scanf("%d%d%d", &f, &ebuf1.to, &ebuf1.cost);
		f-=1;
		ebuf1.to-=1;
		G[f].push_back(ebuf1);
		edge ebuf2;
		ebuf2.to=f;
		ebuf2.cost=ebuf1.cost;
		G[ebuf1.to].push_back(ebuf2);//����ͼ 
	}
	
	solve();
	
	return 0;
}


