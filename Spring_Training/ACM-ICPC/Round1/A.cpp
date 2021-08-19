/**
���ڰ������⽨ͼ��ÿ������ֻ�����Ѿ�ռ��ĳ������ߣ����������N�����У��ͻ���N-1���ߡ�
��������ͼ��һ������
���������ģ���Ҫ������ֱ����Ҳ�����������һ��·������

��ô���������һ��·��? ����DFS
�����ȡһ����������dfs�ҵ�������Զ�ĵ㣬��ô����ҵ��ĵ�һ��������ֱ���ϵ�һ���˵㡣
��������ҵ��ĵ�Ϊ��DFS�ҵ�������Զ�ĵ�(������ֱ������һ���˵㣩

ȷ��������ֱ����ô����������?
��������һ��������ֱ���ϡ�ͳ������ֱ���ϵ�ĸ���������¼·����
���ֱ���ϵ�ĸ���Ϊ��������������ֻ��һ����Ϊ��(S+1)/2����;Ϊż��������������������Ϊ��(S+1)/2�ͣ�S+1)/2+1���㡣
��SΪֱ���ϵ�ĸ��������1��ʼ����)
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
