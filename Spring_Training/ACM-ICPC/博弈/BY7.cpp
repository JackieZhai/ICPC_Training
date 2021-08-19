/**
��ϰ�⣺Crosses and Crosses_POJ 3537
    grundy[i]:=i���ո��ڵ�������Ӯ���
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=2007;

int n, dp[maxn];

int grundy(int x)
{
    if(dp[x]!=-1)
        return dp[x];
    bool vis[maxn];
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=x;i++)
        vis[grundy(max(0,i-3))^grundy(max(x-i-2,0))]=1; //��ֳ�����С����
    for(int i=0;;i++)
        if(!vis[i])
            return dp[x]=i;
}

int main()
{
    scanf("%d",&n);

    memset(dp, -1, sizeof(dp));
    dp[0]=0;

    puts(grundy(n)?"1":"2");

    return 0;
}
