/*
º”¡∑Ã‚£∫Bone Collector_HDU 2602
	
*/
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int w[1005];
int v[1005];
int dp[1005];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&w[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=0;j--)
            {
                if(j>=w[i])//◊¢“‚=∫≈
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
/*
1
5 10
1 2 3 4 5
5 4 3 2 1
*/

