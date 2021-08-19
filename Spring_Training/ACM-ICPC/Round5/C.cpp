#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N=1007;
const ll MOD1=5837501, MOD2=9860381, MOD3=8475871;
const ll INF=LLONG_MAX;

ll X[MAX_N*MAX_N], Y[MAX_N*MAX_N], Z[MAX_N*MAX_N];
int N, M;

ll cost[MAX_N][MAX_N];
ll d[MAX_N];
bool used[MAX_N];
bool isZero[MAX_N*MAX_N];

void dijkstra(int s)
{
    fill(d, d+N, INF);
    fill(used, used+N, false);
    d[s]=0;

    while(true)
    {
        int v=-1;
        for(int u=0; u<N; u++)
        {
            if(!used[u] && (v==-1 || d[u]<d[v]))
                v=u;
        }

        if(v==-1)
            break;
        used[v]=true;
        for(int u=0; u<N; u++)
        {
            d[u]=min(d[u], d[v]+cost[v][u]);
        }
    }
}


int main()
{
    while(scanf("%d%d%lld%lld%lld%lld", &N, &M, &X[0], &X[1], &Y[0], &Y[1])!=EOF)
    {
        for(int k=2; k<N*N; k++)
        {
            X[k]=(12345+X[k-1]*23456%MOD1+X[k-2]*34567%MOD1+X[k-1]*X[k-2]*45678%MOD1)%MOD1;
            Y[k]=(56789+Y[k-1]*67890%MOD2+Y[k-2]*78901%MOD2+Y[k-1]*Y[k-2]*89012%MOD2)%MOD2;
        }
        for(int k=0; k<N*N; k++)
            Z[k]=(X[k]*90123%MOD3+Y[k])%MOD3+1;

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                if(i!=j)
                {
                    cost[i][j]=Z[i*N+j];
                }
                else
                    cost[i][j]=0;

        dijkstra(0);

        fill(isZero, isZero+MAX_N*MAX_N, true);
        for (int i=1; i<N; i++)
        {
            isZero[d[i]%M]=false;
        }
        long long mincost=INF;
        for (long long i=0; i<M; i++)
        {
            if(!isZero[i])
                mincost=min(mincost, i);
        }
        printf("%d\n", mincost);
    }

    return 0;
}
