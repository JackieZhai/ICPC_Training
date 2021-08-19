/**
例题：Priest John's Busiest Day_POJ 3683

*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V=2007;

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

const int MAX_N=1007;

//输入
int N;
int S[MAX_N], T[MAX_N], D[MAX_N]; //S和T是换算成分钟后的时间


int main()
{
    //输入
    scanf("%d", &N);
    for(int i=0;  i<N; i++)
    {
        int a1, a2, b1, b2, c;
        scanf("%d:%d %d:%d %d", &a1, &a2, &b1, &b2, &c);
        S[i]=a1*60+a2;
        T[i]=b1*60+b2;
        D[i]=c;
    }

    //0~N-1: x_i 为真说明在开始举行
    //N~2N-1: -x_i 为假说明在结束举行
    V=2*N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(min(S[i]+D[i], S[j]+D[j]) > max(S[i], S[j]))
            {
                add_edge(i, N+j);
                add_edge(j, N+i);
            }
            if(min(S[i]+D[i], T[j]) > max(S[i], T[j]-D[j]))
            {
                add_edge(i, j);
                add_edge(N+j, N+i);
            }
            if(min(T[i], S[j]+D[j]) > max(T[i]-D[i], S[j]))
            {
                add_edge(N+i, N+j);
                add_edge(j, i);
            }
            if(min(T[i], T[j]) > max(T[i]-D[i], T[j]-D[j]))
            {
                add_edge(N+i, j);
                add_edge(N+j, i);
            }
        }
    }

    scc();


    //判断x和-x是否在不同的强连通分量中
    for(int i=0; i<N; i++)
    {
        if(cmp[i]==cmp[N+i])
        {
            printf("NO\n");
            return 0;
        }
    }

    //如果可满足，给出一组解
    printf("YES\n");
    for(int i=0; i<N; i++)
    {
        if(cmp[i]>cmp[N+i])
            printf("%02d:%02d %02d:%02d\n", S[i]/60, S[i]%60, (S[i]+D[i])/60, (S[i]+D[i])%60);
        else
            printf("%02d:%02d %02d:%02d\n", (T[i]-D[i])/60, (T[i]-D[i])%60, T[i]/60, T[i]%60);
    }



    return 0;
}
