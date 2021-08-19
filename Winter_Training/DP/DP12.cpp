/*
练习题：Space Elevator_POJ 2392 
	dp[i]表示为石块组成i高度时所剩余当前石块的数量。 
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;


const int MAX_N=40007;
int dp[MAX_N];

struct Node
{
    int h,a,c;
}s[407];
int cmp(Node x,Node y)
{
    return x.a<y.a;
}


int main()
{
    int n,i,j,ans=0;
    cin>>n;
    for(i=0; i<n; ++i)
        cin>>s[i].h>>s[i].a>>s[i].c;
    
    sort(s,s+n,cmp);
    
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(i=0; i<n; i++)//多重部分和
        for(j=0; j<=s[i].a; j++)
        {
            if(dp[j]>=0)
				dp[j]=s[i].c;
            else if(j<s[i].h || dp[j-s[i].h] <=0) 
				dp[j]=-1;
            else 
				dp[j]=dp[j-s[i].h]-1;
        }
    
    for (i=s[n-1].a; i>=0; --i)
        if(dp[i]>=0)
        {
            ans=i;
            break;
        }
    cout<<ans<<endl;
    return 0;
    
    
}


