/*
��ϰ�⣺Agri-Net_POJ 1258 
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_V=107, INF=0x3f3f3f3f;

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


int main()
{
	while(scanf("%d", &V)!=EOF)
	{
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++)
				scanf("%d", &cost[i][j]);
	
		printf("%d\n", prim());
	}
	return 0;
}
