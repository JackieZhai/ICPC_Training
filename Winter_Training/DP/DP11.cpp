/*
¡∑œ∞Ã‚£∫Making the Grade_POJ 3666 
	??? 
*/
#include <cstdio>
#include <iostream> 
#include <algorithm> 
using namespace std;  

const int MAX_N = 2007, INF = 0x3f3f3f3f;  
int dp[MAX_N][MAX_N];  
int a[MAX_N], b[MAX_N];  
int n;
  
int main ()  
{  
    scanf("%d", &n);  
    for(int i=1; i<=n; i++)
	{  
        scanf("%d", a+i);  
        b[i]=a[i];  
    }  
    
    sort(b+1, b+n+1);  
  
    for(int i=1; i<=n; i++)
	{  
        for(int j=1; j<=n; j++)
		{  
            dp[i-1][1]=min(dp[i-1][1], dp[i-1][j]);  
            dp[i][j]=abs(a[i]-b[j])+dp[i-1][1];  
        }  
    }  
  
    int ans=INF;  
    for(int i=1; i<=n; i++)  
        ans=min(ans, dp[n][i]);  
  
    printf("%d\n", ans);  
  
    return 0;  
}  
