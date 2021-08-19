/*
���·����ԭ����(Based on Dijkstra Algorithm)��
	����preV[]���飬�Ѹ���ǰ�����������d[e.to]=d[v]+e.cost;���漴�ɡ� 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_V=50005;
const int INF=100005;

struct edge {
	int to, cost;
};
typedef pair<int, int> P;//����first��ʾ��̾��룬second��ʾ����ı�� 

int V, E;
vector<edge> G[MAX_V]; //�±�䵱from
int d[MAX_V];
int preV[MAX_V];//���·�ϵ�ǰ���� 

void dijkstra(int s)
{
	//����first��С����˳�����У���ȡ����̾���Ͷ�Ӧ�Ķ��� 
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+V, INF);
	fill(preV, preV+V, -1);
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
		path.push_back(t);//��������preV[t]��֪��t=s
	//Ҫ��ȡ��s��t�ģ����Է�ת
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
		scanf("%d%d%d", &f, &ebuf1.to, &ebuf1.cost);
		f-=1;
		ebuf1.to-=1;
		G[f].push_back(ebuf1);
		edge ebuf2;
		ebuf2.to=f;
		ebuf2.cost=ebuf1.cost;
		G[ebuf1.to].push_back(ebuf2);//����ͼ 
	}
	
	dijkstra(0);
	vector<int> ans=get_path(V-1);
	for(int i=0; i<ans.size(); i++)
	{
		printf("%d\n", ans[i]+1);
	}
	
	return 0;
}




