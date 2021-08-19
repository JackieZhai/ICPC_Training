#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll x1, x2, y1, y2, n;

    scanf("%lld%lld", &x1, &y1);
    scanf("%lld%lld", &x2, &y2);
    scanf("%lld", &n);

    int ans=0;
    for(int i=0; i<n; i++)
    {
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);

        if(((a*x1+b*y1+c)>0&&(a*x2+b*y2+c)<0)||((a*x1+b*y1+c)<0&&(a*x2+b*y2+c)>0))
            ans++;
    }
    printf("%d\n", ans);


    return 0;
}
