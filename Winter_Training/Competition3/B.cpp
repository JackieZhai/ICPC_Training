/*
	������Floyd�㷨�����Ӧ�ã���Ϊ���������������������·��
	��Bellman��Dijkstraֻ����Դ���·����Ҫÿ�β�ѯ��Ҫ��һ�飬�϶���TLE�� 
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_V=307, INF=0x3f3f3f3f;

int d[MAX_V][MAX_V]; //��ʾ�ߵ�Ȩֵ�������ڵ�ʱ����ΪINF���޸��ߵ�ʱ����d[i][i]=0��
int V, E;

void warshall_floyd(int k)
{
	//for(int k=0; k<V; k++) ����ӽ�㣬���ɳڲ��� 
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++)
				d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
}


int M, Q;
bool mark[MAX_V];

int main()
{
	int kase=0;
	bool flag=false;
	while(scanf("%d%d%d", &V, &M, &Q)!=EOF)
	{
		if(V==0&&M==0&&Q==0)
			break;
		
		if(flag)
			printf("\n");
		flag=true;
		
		for(int i=0; i<V; i++)
		{
			for(int j=0; j<V; j++)
			{
				d[i][j]=INF;
			}
			d[i][i]=0;
		}
		
		printf("Case %d:\n", ++kase);	
		for(int i=0; i<M; i++)
		{
			int f, t, c;
			scanf("%d%d%d", &f, &t, &c);
			if(c<d[f][t]) //���ܴ����ر߻�Ȧ 
				d[f][t]=c;
		}
		
		fill(mark, mark+V, false);
		
		for(int i=0; i<Q; i++)
		{
			int type;
			scanf("%d", &type);
			if(type==0)
			{
				int q;
				scanf("%d", &q);
				if(mark[q]==true)
				{
					printf("ERROR! At point %d\n", q);
					continue;
				}
				mark[q]=true;
				warshall_floyd(q);
			}
			else if(type==1)
			{
				int s,e;
				scanf("%d%d", &s, &e);
				if(mark[s]==false||mark[e]==false)
				{
					printf("ERROR! At path %d to %d\n", s, e);
					continue;
				}
				if(d[s][e]==INF)
					printf("No such path\n");
				else
					printf("%d\n", d[s][e]);
			}
		}
		
	
	} 
	
	return 0;
}
