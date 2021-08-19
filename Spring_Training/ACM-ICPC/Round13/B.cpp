#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;
set<ll> ac, bc;


int main()
{
    scanf("%lld%lld", &n, &m);
    for(int i=0; i<m; i++)
    {
        ll x, y;
        scanf("%lld%lld", &x, &y);
        ac.insert(x);
        bc.insert(y);
        ll a=ac.size(), b=bc.size();
        if(i!=0)
            printf(" ");
        printf("%lld", n*n-(a+b)*n+a*b);
    }
    printf("\n");




    return 0;
}
