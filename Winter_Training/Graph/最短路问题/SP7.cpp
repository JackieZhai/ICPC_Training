/*
��ϰ�⣺Wormholes_POJ 3259 
500������5��test��2000MS����Floyd��ʱ�Ŀ����ԱȽϴ� 
��Ŀ����Ҫ�����ߣ�����ѡ��Bellman-Ford����Ƿ���ڸ��ߡ� 
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N=507, MAX_E=6007, INF=5000007;

int F, N, M, W, E;


struct edge{
	int from, to, cost;
}es[MAX_E];

int d[MAX_N]; //��̾���

//��Ȧ��� 
bool find_negative_loop(int s)
{
	memset(d, 0, sizeof(d));
	for(int i=0; i<N; i++)
		for(int j=0; j<E; j++)
		{
			edge e=es[j];
			if(d[e.to]>d[e.from]+e.cost)
			{
				d[e.to]=d[e.from]+e.cost;
				if(i==N-1)
					return true;
			}
		}	
	return false;
}



int main()
{
	scanf("%d", &F);
	while(F--)
	{
		scanf("%d%d%d", &N, &M, &W);
		for(int i=0; i<M*2; i+=2)
		{
			scanf("%d%d%d", &es[i].from, &es[i].to, &es[i].cost);
			es[i+1].from=es[i].to;
			es[i+1].to=es[i].from;
			es[i+1].cost=es[i].cost;
		}
		for(int i=M*2; i<M*2+W; i++)
		{
			scanf("%d%d%d", &es[i].from, &es[i].to, &es[i].cost);
			es[i].cost=-es[i].cost;
		}
		E=M*2+W+1;
		if(find_negative_loop(1))
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	
	return 0;
}
