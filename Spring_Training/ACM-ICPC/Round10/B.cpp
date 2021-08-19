#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getDigit(ll n)
{
    ll ret=0;
    while(n!=0)
    {
        ret++;
        n/=10;
    }
    return ret;
}


ll sum[]={0, 1, 11, 192, 2893, 38894, 488895, 5888896, 68888897, 788888898, 8888888899};

int main()
{
    ll num;
    scanf("%I64d", &num);
    ll c=getDigit(num);
    ll m=pow(10, c-1)+0.5;
    ll ans=sum[c]+(num-m)*c;
    printf("%I64d\n", ans);




    return 0;
}
