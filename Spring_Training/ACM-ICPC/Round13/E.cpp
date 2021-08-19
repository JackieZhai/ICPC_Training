#include <bits/stdc++.h>

using namespace std;
const int maxm = 2e5 + 10;
const int maxn = 2e5 + 10;
typedef long long ll;
struct Edges{
    int u,v;
}edge[maxm];
vector<int> G[maxn];

int cnt[maxn];
int dfs(int cur,int from){
    for(int i = 0 ; i < G[cur].size() ; i ++){
        int v = G[cur][i];
        if(v == from) continue;
        cnt[cur] += dfs(v,cur);
    }
    return cnt[cur];
}

int main (){
    int n,k;
    scanf("%d %d", &n,&k);
    for(int i = 1 ; i <= k*2 ; i ++){
        int tmp;
        scanf("%d", &tmp);
        cnt[tmp] = 1;
    }
    int cn = 0;
    for(int i = 0 ; i < n-1 ; i ++){
        int u,v;
        scanf("%d %d", &u,&v);
        edge[i].u = u;
        edge[i].v = v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    ll exp = 0;
    for(int i = 0 ; i < n-1 ; i ++){
        Edges & e = edge[i];
        int tt = min(cnt[e.u],cnt[e.v]);
        int tmp = min(2*k-tt,tt);
        exp += tmp;
    }
    printf("%I64d\n",exp);
}
