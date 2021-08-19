#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_V=107;

double cost[MAX_V][MAX_V];
double mincost[MAX_V];
bool used[MAX_V];
int V;

double prim()
{
	for(int i=0; i<V; i++)
	{
		mincost[i]=999999999;
		used[i]=false;
	}
	mincost[0]=0;
	double res=0;

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

double poi[107][2];


int main()
{
    while(scanf("%d", &V)!=EOF)
    {
        for(int i=0; i<V; i++)
        {
            scanf("%lf%lf", &poi[i][0], &poi[i][1]);
        }

        for(int i=0; i<V; i++)
            for(int j=i+1; j<V; j++)
            {
                double cos=sqrt((poi[i][0]-poi[j][0])*(poi[i][0]-poi[j][0])+(poi[i][1]-poi[j][1])*(poi[i][1]-poi[j][1]));
                cost[i][j]=cos;
                cost[j][i]=cos;
            }

        printf("%.2lf\n", prim());
    }


    return 0;
}
