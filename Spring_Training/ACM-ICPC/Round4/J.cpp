#include <bits/stdc++.h>
using namespace std;


int M, N, K;
typedef long long ll;

int main()
{
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++)
    {
        ll M, N, K;
        scanf("%lld%lld%lld", &M, &N, &K);
        ll maxarr=M*M*N*N;

        double ans=0;
        for(ll r=1; r<=M; r++)
        {
            for(ll c=1; c<=N; c++)
            {
                ll tmp=(M*(c-1))*(M*(c-1)) + ((M-r)*N)*((M-r)*N) + (M*(N-c))*(M*(N-c)) + ((r-1)*N)*((r-1)*N) - ((r-1)*(c-1))*((r-1)*(c-1)) - ((M-r)*(c-1))*((M-r)*(c-1)) - ((M-r)*(N-c))*((M-r)*(N-c)) - ((r-1)*(N-c))*((r-1)*(N-c));
                ans+=(double)1-(pow((double)tmp/maxarr, K));
            }
        }

        printf("Case #%d: %.0f\n", kase, ans);
    }

    return 0;
}


