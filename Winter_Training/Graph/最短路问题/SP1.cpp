/*
��Դ���·����(Bellman-Ford Algorithm)��
	��Դ���·�ǹ̶�һ����㣬�������������е�֮��ľ�������·��(����������·���⸴�Ӷ�һ��) 
	����������и��ߵ������ 
*/ 
#include <bits/stdc++.h>
using namespace std;

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
