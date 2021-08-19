/**
练习题：MooFest_POJ 1990

*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

//BIT均是index-1
ll bit[20007]; //下标是坐标，统计牛的个数
int n;
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

ll bit2[20007]; //下标是坐标，统计牛的距离
int n2;
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
    while(i<=n2)
    {
        bit2[i]+=x;
        i+=i&-i;
    }
}

int m;
struct Node{
    ll v, x;
    friend bool operator < (const Node &a, const Node &b)
    {
        return a.v<b.v;
    }
}a[20007];


int main()
{
    while(scanf("%d", &m)!=EOF)
    {
        for(int i=1; i<=m; i++)
            scanf("%d%d", &a[i].v, &a[i].x);

        sort(a+1, a+m+1);

        memset(bit, 0, sizeof(bit));
        memset(bit2, 0, sizeof(bit2));
        n=20000;
        n2=20000;
        ll ans=0;
        for(int i=1; i<=m; i++)
        {
            //从小牛开始
            int v=a[i].v;
            int x=a[i].x;
            ll left=sum(x-1);
            ll right=sum(20000)-sum(x);
            ans+=v*((left*x-sum2(x-1)) + ((sum2(20000)-sum2(x))-right*x));
            //添加此牛的信息
            add(x, 1);
            add2(x, x);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
