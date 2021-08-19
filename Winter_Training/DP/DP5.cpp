/*
练习题：Cheapest Palindrome_POJ 3280
	dp递推：
	这个是一个很明显的区间dp
我们定义dp[i][j]为区间i到j变成回文的最小代价。
初始化dp[i][i]为0，因为一个字母是零；那么对于dp[i][j]有三种情况： 
首先：对于一个串如果a[i]==a[j]，那么dp[i][j]=dp[i+1][j-1]:
其次：如果dp[i+1][j]是回文串，那么dp[i][j]=dp[i+1][j]+min(add[i], del[i])； 
最后：如果dp[i][j-1]是回文串，那么dp[i][j]=dp[i][j-1] + min(add[j], del[j])。 
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX_N = 256, MAX_M = 2007;  
int cost[MAX_N];  
int dp[MAX_M][MAX_M]; 
int n,m;  
string a;
  
int main()
{  
    scanf("%d%d",&n,&m);
    cin>>a;  
    char c;
	int x,y;  
    for(int i=0; i<n; i++)  
    {  
        cin>>c>>x>>y;  
        cost[c]=min(x,y);  
    } 
        
    memset(dp,0,sizeof(dp)); 
        
    for(int k=1; k<a.size(); k++)  
    {  
        for(int i=0,j=k; j<a.size(); i++,j++)  
        { 
            dp[i][j]=0x3f3f3f3f;  
            if(a[i]==a[j])  
                dp[i][j]=dp[i+1][j-1];  
            else  
            {  
                dp[i][j]=min(dp[i+1][j] + cost[a[i]],dp[i][j]);  
                dp[i][j]=min(dp[i][j-1] + cost[a[j]],dp[i][j]);  
            }  
        }  
    }
    
    printf("%d\n",dp[0][a.size()-1]);  
        
    
    return 0;  
}  
