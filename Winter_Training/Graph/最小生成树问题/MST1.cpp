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
		
		
		//�˴�����ʹ�ö���ά��������ʱ�临�Ӷ� 
		for(int u=0; u<V; u++)
		{
			mincost[u]=min(mincost[u], cost[v][u]);
		}
	}
	
	return res;
}

