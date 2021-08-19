/*
加练题：Communication System_POJ 1018
	dp[i][j]表示前i个设备，公共带宽为j时的最小费用。 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=105;
const int maxm=10005;

int b[maxn];
int p[maxn];
int dp[maxn][maxm];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
	{
        int n,m;
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        int maxb=0;
        for(int i=1;i<=n;i++)
		{
            scanf("%d",&m);
            for(int j=1;j<=m;j++)
			{
                scanf("%d%d",&b[j],&p[j]);
                maxb=max(maxb,b[j]);
            }
            
            if(i==1)
			{//第一层直接初始化
                for(int j=1;j<=m;j++)
                    dp[i][b[j]]=p[j];
                continue;
            }
            
            for(int k=0;k<=maxb;k++)
			{
                if(dp[i-1][k]==-1)continue;
                for(int j=1;j<=m;j++)
				{
                    int mb=min(k,b[j]);//当选择第J个厂商时、取当前最小的带宽
                    if(dp[i][mb]==-1)//如果这种带宽没有别的组合达到、则直接由上一层加
                        dp[i][mb]=dp[i-1][k]+p[j];
                    else//如果这种组合已经有值了、则选择小的
                        dp[i][mb]=min(dp[i][mb],dp[i-1][k]+p[j]);
                }
            }
        }
        
        double ans=0;
        for(int i=0;i<=maxb;i++)//遍历每一种带宽的对应的最小总价格
            ans=max(ans,(1.0*i)/(double)dp[n][i]);
        printf("%.3f\n",ans);
        
    }
    
    return 0;
}
