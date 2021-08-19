#include<bits/stdc++.h>
using namespace std;

const int MAXN=3e5+100;

int c[MAXN];
vector<int> edge[MAXN];
int sign[MAXN];
set<int> s;
int cou[MAXN];
int cnt=0, Max=0;

void dfs(int i)
{
    sign[i]=1;
    if(s.count(c[i])==0)
        cou[c[i]]=1;
    else
        cou[c[i]]++;
    s.insert(c[i]);
    cnt++;
    Max=max(Max,cou[c[i]]);
    for(int j=0; j<edge[i].size(); j++)
    {
        if(sign[edge[i][j]]==0)
            dfs(edge[i][j]);
    }
}

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    for(int i=1; i<=n; i++)
        scanf("%d",&c[i]);
    for(int i=1; i<=m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(sign[i]!=0)
            continue;
        cnt=Max=0;
        s.clear();
        dfs(i);
        ans+=cnt-Max;
    }
    cout<<ans<<endl;
    return 0;
}
