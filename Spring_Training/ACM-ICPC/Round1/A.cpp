/**
由于按照题意建图，每个城市只是与已经占领的城市连边，所以如果有N个城市，就会连N-1条边。
即所建的图是一棵树。
找树的中心，先要找树的直径（也就是树上最长的一条路径）。

怎么找树上最长的一条路径? 两次DFS
先随便取一个点做根，dfs找到离它最远的点，那么这个找到的点一定是树的直径上的一个端点。
再以这个找到的点为根DFS找到离它最远的点(即树的直径的另一个端点）

确定了树的直径怎么找树的中心?
树的中心一定在树的直径上。统计树的直径上点的个数，并记录路径。
如果直径上点的个数为奇数个，则中心只有一个，为第(S+1)/2个点;为偶数个，则中心有两个，为第(S+1)/2和（S+1)/2+1个点。
（S为直径上点的个数，点从1开始计数)
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define maxn 1010

using namespace std;

int n,id[maxn];
double x[maxn],y[maxn],z[maxn],dis[maxn][maxn],dp[maxn];
int path[maxn],pre[maxn];
vector<int> G[maxn];

double dist(int u,int v)
{
    double dx = x[u]-x[v];
    double dy = y[u]-y[v];
    double dz = z[u]-z[v];
    return sqrt(dx*dx+dy*dy+dz*dz);
}

void build()
{
    for(int i=1;i<=n;i++)
    {
        double maxl = 9999999;
        int obj=-1;
        for(int j=1;j<i;j++)
        {
            if(dis[id[i]][id[j]]<maxl)
            {
                maxl = dis[id[i]][id[j]];
                obj = j;
            }
        }
        if(obj==-1) continue;
        int u = id[i],v = id[obj];
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int x,int fa,int len)
{
    dp[x] = len;
    for(int i=0;i<G[x].size();i++)
    {
        int u = G[x][i];
        if(u!=fa)
            dfs(u,x,len+1);
    }
}

void dfs1(int x,int fa,int len)
{
    dp[x] = len;
    pre[x] = fa;
    for(int i=0;i<G[x].size();i++)
    {
        int u = G[x][i];
        if(u!=fa)
            dfs1(u,x,len+1);
    }
}

int main()
{
    int p1,p2;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(int i=0;i<=1005;i++)
            G[i].clear();
        memset(pre,0,sizeof(pre));
        memset(path,0,sizeof(path));
        memset(dis,0,sizeof(dis));
        memset(pre,0,sizeof(pre));

        for(int i=1;i<=n;i++)
        {
            scanf("%d%lf%lf%lf",&id[i],&x[i],&y[i],&z[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[id[i]][id[j]] = dist(i,j);
            }
        }
        build();
        memset(dp,0,sizeof(dp));
        dfs(id[1],-1,0);
        double tmp = 0;
        for(int i=1;i<=n;i++)
        {
            if(dp[id[i]]>tmp)
            {
                tmp = dp[id[i]];
                p1 = id[i];
            }
        }
        memset(dp,0,sizeof(dp));
        dfs1(p1,-1,0);
        tmp = 0;
        for(int i=1;i<=n;i++)
        {
            if(dp[id[i]]>tmp)
            {
                tmp = dp[id[i]];
                p2 = id[i];
            }
        }
        int s = 0;
        for(int i=p2;i!=-1;i=pre[i])
        {
            path[++s] = i;
        }
        int mid = (s+1)/2;
        if(s&1)
        {
            printf("%d\n",path[mid]);
        }
        else
        {
            int a = path[mid],b = path[mid+1];
            if(a>b)
            {
                int t = a;
                a = b;
                b = t;
            }
            printf("%d %d\n",a,b);
        }
    }
    return 0;
}
