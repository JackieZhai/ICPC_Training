#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;

struct edge{
	int from, to, cost;
};

edge es[150007];

int d[50007];
int V, E;

void bellmanford(int s)
{
	for(int i=0; i<V; i++)
	{
		d[i]=INF;
	}
	d[s]=0;
	int kase=V;
	while(kase--)
	{
		bool update=false;
		for(int i=0; i<E; i++)
		{
			edge e=es[i];
			if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost)
			{
				d[e.to]=d[e.from]+e.cost;
				update=true;
			}
		}
		if(!update)
			break;
	}
}


int main()
{
	scanf("%d", &E);
	int minN=INF;
	int maxN=0;
	for(int i=0; i<E; i++)
	{
		int f,t,c;
		scanf("%d%d%d", &f, &t, &c);
		es[i]=(edge){f, t, -c};
		minN=min(minN, f);
		maxN=max(maxN, t);
	}
	V=maxN;
	for(int i=0; i<maxN; i++)
	{
		es[i+E]=(edge){i, i+1, 0};
	}
	for(int i=0; i<maxN; i++)
	{
		es[i+2*E]=(edge){i+1, i, 1};
	}
	E+=2*maxN;
	
	bellmanford(minN); 
	
	printf("%d\n", d[maxN]);
	
	
	
	
	return 0;
}
