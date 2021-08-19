//1. 染色法判断是否为二分图
//2. 二分图最大匹配大白
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_V=207;

vector<int> G[MAX_V];
int V, E;
int color[MAX_V];

bool dfs(int v, int c)
{
	color[v]=c;
	for(int i=0; i<G[v].size(); i++)
	{
		if(color[G[v][i]]==c)
			return false;
		if(color[G[v][i]]==0 && !dfs(G[v][i], -c))
			return false;
	}
	return true;
}

bool judging()
{
	for(int i=0; i<V; i++)
	{
		if(color[i]==0)
		{
			if(!dfs(i, 1))
			{
				return false;
			}
		}
	}
	return true;
}


int match[MAX_V];
bool used[MAX_V];

bool dfs2(int v)
{
    used[v]=true;
    for(int i=0; i<G[v].size(); i++)
    {
        int u=G[v][i], w=match[u];
        if(w<0 || !used[w] && dfs2(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}

int matching()
{
    int res=0;
    memset(match, -1, sizeof(match));
    for(int v=0; v<V; v++)
    {
        if(match[v]<0)
        {
            memset(used, 0, sizeof(used));
            if(dfs2(v))
                res++;
        }
    }
    return res;
}


int main()
{
	while(scanf("%d%d", &V, &E)!=EOF)
    {
        for(int i=0; i<V; i++)
            G[i].clear();
        memset(color, 0, sizeof(color));
        for(int i=0; i<E; i++)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            s--, t--;
            G[s].push_back(t);
            G[t].push_back(s);
        }

        if(!judging())
        {
            printf("No\n");
        }
        else
        {
            printf("%d\n", matching());
        }
    }



	return 0;
}
