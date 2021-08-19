//布尔公式为(av-b)^(bvc)^(-cv-a)
//构造六个顶点，分别对应a,b,c,-a,-b,-c

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V=10;

int V; //顶点数
vector<int> G[MAX_V]; //图的邻接表示
vector<int> rG[MAX_V]; //把边反向后的图
vector<int> vs; //后序遍历顺序的顶点列表
bool used[MAX_V]; //访问标记
int cmp[MAX_V]; //所属强联通分量的拓扑序

void add_edge(int from, int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v)
{
    used[v]=true;
    for(int i=0; i<G[v].size(); i++)
        if(!used[G[v][i]])
            dfs(G[v][i]);
    vs.push_back(v);
}

void rdfs(int v, int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0; i<rG[v].size(); i++)
        if(!used[rG[v][i]])
            rdfs(rG[v][i], k);
}

int scc()
{
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v=0; v<V; v++)
        if(!used[v])
            dfs(v);
    memset(used, 0, sizeof(used));
    int k=0;
    for(int i=vs.size()-1; i>=0;  i--)
        if(!used[vs[i]])
            rdfs(vs[i], k++);
    return k; //代表共有几个强连通分量
}


int main()
{
    V=6;
    add_edge(3, 4);
    add_edge(1, 0);
    add_edge(4, 2);
    add_edge(5, 1);
    add_edge(2, 3);
    add_edge(0, 5);

    scc();

    //判断x和-x是否在不同的强连通分量中
    for(int i=0; i<3; i++)
    {
        if(cmp[i]==cmp[3+i])
        {
            printf("NO\n");
            return 0;
        }
    }

    //如果可满足，给出一组解
    printf("YES\n");
    for(int i=0; i<3; i++)
    {
        if(cmp[i]>cmp[3+i])
            printf("true\n");
        else
            printf("false\n");
    }



    return 0;
}
