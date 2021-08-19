/**
�㷨ģ�壺����ͼƥ��
    ���Ӷȣ�O(|E||V|)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1007;

int V;
vector<int> G[MAX_V];
int match[MAX_V]; //��ƥ��Ķ���
int used[MAX_V];

void add_edge(int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v)
{
    used[v]=true;
    for(int i=0; i<G[v].size(); i++)
    {
        int u=G[v][i], w=match[u];
        if(w<0 || !used[w] && dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}

//������ͼ�����ƥ��
int bipartite_matching()
{

    int res=0;
    memset(match, -1, sizeof(match));
    for(int v=0; v<V; v++)
    {
        if(match[v]<0)
        {
            memset(used, 0, sizeof(used));
            if(dfs(v))
                res++;
        }
    }
    return res;
}

int main()
{

    return 0;
}
