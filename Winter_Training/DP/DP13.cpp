/*
练习题：Cow Exhibition_POJ 2184
	01背包问题，但是遍历的下标有负值，需要进行偏移。 
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int INF=0x3f3f3f3f;
const int MAX_N=107;
int dp[200007];
int bias=100000;
int s[MAX_N], f[MAX_N];
int n;


int main()
{
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&s[i],&f[i]);
    }
    
    
    for(int i=0;i<=200000;i++)
		dp[i]=-INF;
    dp[bias]=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>0)//正的是逆序 
        {
            for(int j=200000; j>=s[i]; j--)
                if(dp[j-s[i]]>-INF)
                	dp[j]=max(dp[j], dp[j-s[i]]+f[i]);
        }
        else//负的是顺序 
        {
            for(int j=0; j<=200000+s[i]; j++)
                if(dp[j-s[i]]>-INF)
                	dp[j]=max(dp[j], dp[j-s[i]]+f[i]);
        }
    }
    
    int ans=0;
    for(int i=100000;i<=200000;i++)
        if(dp[i]>=0&&dp[i]+i-100000>ans)
            ans=dp[i]+i-100000;
    printf("%d\n",ans);
    
    return 0;
}
