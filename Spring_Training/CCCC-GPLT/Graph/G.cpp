#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_V=107;
const int INF=0x3f3f3f3f;

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



		//此处可以使用堆来维护，降低时间复杂度
		for(int u=0; u<V; u++)
		{
			mincost[u]=min(mincost[u], cost[v][u]);
		}
	}

	return res;
}



int main()
{
    int E;
    while(scanf("%d%d", &E, &V)!=EOF)
    {
        if(E==0)
            break;

        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                cost[i][j]=INF;
        for(int i=0;  i<E; i++)
        {
            int f, t, c;
            scanf("%d%d%d", &f, &t, &c);
            f--, t--;
            if(cost[f][t]>c)
            {
                cost[f][t]=c;
                cost[t][f]=c;
            }
        }

        int ans=prim();
        if(ans>=INF)
            printf("?\n");
        else
            printf("%d\n", ans);






    }





    return 0;
}
