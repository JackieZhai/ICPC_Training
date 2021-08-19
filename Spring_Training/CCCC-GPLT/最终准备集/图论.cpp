///ͼ�����


/*
��Դ���·����(Bellman-Ford Algorithm)��
	��Դ���·�ǹ̶�һ����㣬�������������е�֮��ľ�������·��(����������·���⸴�Ӷ�һ��)
	����������и��ߵ������
*/
struct edge{
	int from, to, cost;
}es[MAX_E];

int d[MAX_V]; //��̾���
int V, E;

void shortest_path(int s)
{
	for(int i=0; i<V; i++)
		d[i]=INF;
	d[s]=0;
	while(true) //��������ڸ�Ȧ�����Ӷ���O(|V|X|E|)
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
��Դ���·����(Dijkstra Algorithm)��
	���ڲ����ڸ��ߣ��ҵ�d[i]��С�Ķ��������̾����Ѿ�ȷ���Ķ��㡣
*/
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


/*
������������·����(Floyd-Warshall Algorithm)��
	��DP��⣬����ʽΪ��
d[0][i][j]=cost[i][j]
d[k][i][j]=min(d[k-1][i][j], d[k-1][i][k]+d[k-1][k][j])
���ɿ��ԸĽ�Ϊd[i][j]����ʽ��
	���Ӷ�: O(|V|^3)��
	���Դ�����Ǹ��������⣻���ж��Ƿ��и�Ȧ��ֻ��Ҫ�ж��Ƿ����d[i][i]<0��
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 107; //�����ܲ����ö������Ƕ������󲻴�
const int INF = 100007;

int d[MAX_V][MAX_V]; //��ʾ�ߵ�Ȩֵ�������ڵ�ʱ����ΪINF���޸��ߵ�ʱ����d[i][i]=0��
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
��С������(Minimum Spanning Tree)����(Prim Algorithm)��
	Prim��Dijkstra�����ƣ����ǴӶ���������ϼӱߵĹ���(ֱ�����㼯�ϵ�����X==V)��
	������СȨֵ�ı�mincost[]ͬDijkstraһ�������ȶ���ά����
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
		//�Ӳ�����X�Ķ�����ѡȡ��X����Ȩֵ��С�Ķ���
		for(int u=0; u<V; u++)
		{
			if(!used[u] && (v==-1||mincost[u]<mincost[v]))
				v=u;
		}

		if(v==-1)
			break;
		used[v]=true; //�Ѷ���v����X
		res+=mincost[v]; //�ѱߵĳ��ȼ��뵽�����

		for(int u=0; u<V; u++)
		{
			mincost[u]=min(mincost[u], cost[v][u]);
		}
	}

	return res;
}


///����ֱ��
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
