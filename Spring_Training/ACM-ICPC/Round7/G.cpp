#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a, b;

int main()
{
    scanf("%d%lld%lld", &n, &a, &b);
    for(int kase=0; kase<n; kase++)
    {
        if(kase!=0)
            printf(" ");
        ll x;
        scanf("%lld", &x);
        ll c=x*a/b;
        ll ans=(x*a-b*c)/a;

        printf("%lld", ans);
    }
    printf("\n");



    return 0;
}
