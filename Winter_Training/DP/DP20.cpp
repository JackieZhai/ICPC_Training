/*
加练题：Python Indentation_Codeforces 909C
	dp[i][j] which stores the number of such programs ending with statement i at indent j.
	if i is a loop statement:
	dp[i+1][0]=0 and dp[i+1][j]=dp[i][j-1] for j>0. 
	if i is a simple statement:
	dp[i+1][j]=∑(k=j→N-1)dp[i][k].
	the answer is:
	∑(k=0→N-1)dp[N-1][k].
*/
#include <bits/stdc++.h>
using namespace std;

/*超时代码 
int dp[5007][5007];
int N;
const int INF=1e9+7;

int main()
{
	scanf("%d", &N);
	
	dp[0][0]=1;
	
	for(int i=0; i<N; i++)
	{
		getchar();
		char type;
		scanf("%c", &type);
		if(type=='f')
		{
			dp[i+1][0]=0;
			for(int j=1; j<=i+1; j++)
			{
				dp[i+1][j]=dp[i][j-1];
			}
		}
		else
		{
			for(int j=0; j<=i+1; j++)
				for(int k=j; k<=i+1; k++)
				{
					if(dp[i][k]!=0)
						dp[i+1][j]=(dp[i+1][j]+dp[i][k])%INF;
				}
		}
	}
	
	int ans=0;
	for(int k=0; k<N; k++)
		if(dp[N-1][k]!=0)
			ans=(ans+dp[N-1][k])%INF;
	printf("%d\n", ans);
	
	return 0;
}
*/



const int MOD=1e9+7;
int dp[5007][5007];
char c[5007];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
		getchar();
		scanf("%c", &c[i]);
	}
	
    for(int i=0; i<n; i++)
		dp[n][i]=1;
	
    for(int i=n-1;i>=1;i--)
    {
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum=(sum+dp[i+1][j])%MOD;
            if(c[i]=='f')
				dp[i][j]=(dp[i][j]+dp[i+1][j+1])%MOD;
            else 
				dp[i][j]=(dp[i][j]+sum)%MOD;
        }
    }
    printf("%d\n", dp[1][0]);
    
    return 0;
}

