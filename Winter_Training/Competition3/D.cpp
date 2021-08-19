#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_V=1e5+7;
const ll INF=0x1f1f1f1f1f1f1f1f;

struct edge {
	int to;
	ll cost;
};
typedef pair<int, int> P;//利用first表示最短距离，second表示顶点的编号 

int V, E;
vector<edge> G[MAX_V]; //下标充当from
ll d[MAX_V];
int preV[MAX_V];//最短路上的前趋点 

void dijkstra(int s)
{
	//按照first从小到大顺序排列，先取出最短距离和对应的顶点 
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+V, INF);
	fill(preV, preV+V, -1);
	d[s]=0;
	que.push(P(0,s));
	
	while(que.size()) //复杂度为O(|E|Xlog|V|) 
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
				preV[e.to]=v;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}

vector<int> get_path(int t)
{
	vector<int> path;
	for(; t!=-1; t=preV[t])
		path.push_back(t);//不断沿着preV[t]走知道t=s
	//要获取从s到t的，所以翻转
	reverse(path.begin(), path.end());
	return path; 
}


int main()
{
	//From SP3
	scanf("%d%d", &V, &E);
	for(int i=0; i<E; i++)
	{
		int f;
		edge ebuf1;
		scanf("%d%d%lld", &f, &ebuf1.to, &ebuf1.cost);
		f-=1;
		ebuf1.to-=1;
		G[f].push_back(ebuf1);
		edge ebuf2;
		ebuf2.to=f;
		ebuf2.cost=ebuf1.cost;
		G[ebuf1.to].push_back(ebuf2);//无向图 
	}
	
	dijkstra(0);
	if(d[V-1]==INF)
	{
		printf("-1\n");
		return 0;
	}
	
	vector<int> ans=get_path(V-1);
	for(int i=0; i<ans.size(); i++)
	{
		printf("%d ", ans[i]+1);
	}
	printf("\n");
	return 0;
}
