/*
加练题： Max Sum Plus Plus_HDU 1024
	
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define N 1000000
#define INF 0x7fffffff

int a[N+10];
int dp[N+10],Max[N+10];//max( dp[i-1][k] ) 就是上一组 0....j-1 的最大值。

int main()
{
    int n,m,mmax;
    while (~scanf("%d%d",&m,&n))
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        memset(Max,0,sizeof(Max));
        for (int i=1;i<=m;i++)//分成几组
        {
            mmax=-INF;
            for (int j=i;j<=n;j++)//j个数分成i组，至少要有i个数
            {
                dp[j]=max(dp[j-1]+a[j],Max[j-1]+a[j]);
                Max[j-1]=mmax;
                mmax=max(mmax,dp[j]);
            }
        }
        printf ("%d\n",mmax);
    }
    return 0;
}

