#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

//index-1
ll bit[100007], n;
ll sum(int i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i, ll x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
//index-1
ll bit2[100007], n2;
ll sum2(int i)
{
    ll s=0;
    while(i>0)
    {
        s+=bit2[i];
        i-=i&-i;
    }
    return s;
}
void add2(int i, ll x)
{
    while(i<=n)
    {
        bit2[i]+=x;
        i+=i&-i;
    }
}


int q;

int main()
{
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; i++)
    {
        ll x;
        scanf("%lld", &x);
        add(i, x);
    }
    for(int i=1; i<=q; i++)
    {
        char type;
        getchar();
        type=getchar();
        if(type=='Q')
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", (sum2(r)*r+sum(r))-(sum2(l-1)*(l-1)+sum(l-1)));
        }
        else
        {
            int l, r;
            ll ad;
            scanf("%d%d%lld", &l, &r, &ad);
            add2(l, ad);
            add2(r, -ad);
            add(l, ad*(-l+1));
            add(r, ad*r);
        }
    }




    return 0;
}
