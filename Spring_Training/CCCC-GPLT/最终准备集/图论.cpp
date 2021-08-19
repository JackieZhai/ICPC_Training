///图论相关


/*
单源最短路问题(Bellman-Ford Algorithm)：
	单源最短路是固定一个起点，求它到其他所有点之间的距离的最短路。(和两点间最短路问题复杂度一样)
	常用于求解有负边的情况。
*/
struct edge{
	int from, to, cost;
}es[MAX_E];

int d[MAX_V]; //最短距离
int V, E;

void shortest_path(int s)
{
	for(int i=0; i<V; i++)
		d[i]=INF;
	d[s]=0;
	while(true) //如果不存在负圈，复杂度是O(|V|X|E|)
	{
		bool update=false;
		for(int i=0; i<E; i++)
		{
			edge e=es[i];
			if(d[e.from!=INF && d[e.to]>d[e.from]+e.cost])
			{
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(!update)
			break;
	}
}


/*
单源最短路问题(Dijkstra Algorithm)：
	由于不存在负边，找到d[i]最小的顶点就是最短距离已经确定的顶点。
*/
struct edge {
	int to, cost;
};
typedef pair<int, int> P;//利用first表示最短距离，second表示顶点的编号

int V;
vector<edge> G[MAX_V]; //下标充当from
int d[MAX_V];

void dijkstra(int s)
{
	//按照first从小到大顺序排列，先取出最短距离和对应的顶点
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+V, INF);
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
				que.push(P(d[e.to],e.to));
			}
		}
	}
}


/*
任意两点间最短路问题(Floyd-Warshall Algorithm)：
	用DP求解，递推式为：
d[0][i][j]=cost[i][j]
d[k][i][j]=min(d[k-1][i][j], d[k-1][i][k]+d[k-1][k][j])
依旧可以改进为d[i][j]的形式。
	复杂度: O(|V|^3)。
	可以处理边是负数的问题；而判断是否有负圈，只需要判断是否存在d[i][i]<0。
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 107; //弗法能不能用都看的是顶点数大不大
const int INF = 100007;

int d[MAX_V][MAX_V]; //表示边的权值（不存在的时候设为INF，无负边的时候设d[i][i]=0）
int V, E;

void warshall_floyd()
{
	for(int k=0; k<V; k++)
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++)
				d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
}

int main()
{
	scanf("%d%d", &V, &E);

	for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
			d[i][j]=INF;
		d[i][i]=0;
	}


	for(int i=0; i<E; i++)
	{
		int buf1, buf2, buf3;
		scanf("%d%d%d", &buf1, &buf2, &buf3);
		d[buf1-1][buf2-1]=buf3;
		d[buf2-1][buf1-1]=buf3;
	}


	warshall_floyd();
	printf("%d\n", d[0][V-1]);

	return 0;
}


/*
最小生成树(Minimum Spanning Tree)问题(Prim Algorithm)：
	Prim和Dijkstra很类似，都是从顶点出发不断加边的过程(直到顶点集合的数量X==V)；
	查找最小权值的边mincost[]同Dijkstra一样用优先队列维护。
*/
#include <bits/stdc++.h>
using namespace std;

int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;

int prim()
{
	for(int i=0; i<V; i++)
	{
		mincost[i]=INF;
		used[i]=false;
	}
	mincost[0]=0;
	int res=0;

	while(true)
	{
		int v=-1;
		//从不属于X的顶点中选取从X到其权值最小的顶点
		for(int u=0; u<V; u++)
		{
			if(!used[u] && (v==-1||mincost[u]<mincost[v]))
				v=u;
		}

		if(v==-1)
			break;
		used[v]=true; //把顶点v加入X
		res+=mincost[v]; //把边的长度加入到结果里

		for(int u=0; u<V; u++)
		{
			mincost[u]=min(mincost[u], cost[v][u]);
		}
	}

	return res;
}


///树的直径
bfs(1);
int Md=-1, Mn;
for(int i=0; i<V; i++)
{
    if(Md<dis[i])
    {
        Md=dis[i];
        Mn=i;
    }
}
bfs(Mn);
int L=-1;
for(int i=0; i<V; i++)
{
    if(L<dis[i])
        L=dis[i];
}
