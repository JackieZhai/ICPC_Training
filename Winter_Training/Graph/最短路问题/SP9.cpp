/*
��ϰ�⣺Road Construction_AOJ 2249 
	˫cost��������Dijkstra�� 
*/ 

#include <bits/stdc++.h>
using namespace std;

const int MAX_V=10007;


struct edge {
	int to, dis, cost;
	
	edge(){}
	edge(int to, int dis, int cost):to(to), dis(dis), cost(cost){}//���캯��
	
	bool operator > (const edge &b) const
	{
		return dis!=b.dis? dis>b.dis : cost>b.cost;
	}//�ȱȽϾ��룬�ٱȽϻ��� 
};

int V, E;
vector<edge> G[MAX_V]; //�±�䵱from
int mark[MAX_V];

int dijkstra()
{
	int res=0;
	//����edge�����˳�����У���ȡ����ʡ��· 
	priority_queue<edge, vector<edge>, greater<edge> > que;
	fill(mark, mark+V, false);
	que.push(edge(0,0,0));
	
	while(que.size())
	{
		edge p = que.top();
		que.pop();
		int v=p.to;
		if(mark[v])
			continue;
		mark[v]=true;
		res+=p.cost;
		for(int i=0; i<G[v].size(); i++)
		{
			edge e=G[v][i];
			que.push(edge(e.to, p.dis+e.dis, e.cost));
		}
	}
	
	return res;
}

int main()
{
	while(scanf("%d%d", &V, &E)!=EOF)
	{
		if(V==0&&E==0)
			break;
		
		for(int i=0; i<=V; i++)
			G[i].clear();
		
		for(int i=0; i<E; i++)
		{
			int f, t, d, c;
			scanf("%d%d%d%d", &f, &t, &d, &c);
			f--;
			t--;
			G[f].push_back(edge(t,d,c));
			G[t].push_back(edge(f,d,c));
		}
		
		printf("%d\n", dijkstra());
	}
	
	
	return 0;
}




