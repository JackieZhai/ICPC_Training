/*
���������⣺
	��n�����������Ʒ�������ǻ��ֳɲ�����m�飬�󻮷ַ�����ģM��������
	1<=m<=n<=1000, 2<=M<=10000
	(����Ϊn��m����) 
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_M=1007, MAX_N=1007;
const int M=1e9+7;

int n, m;
int dp[MAX_M][MAX_N];

void solve()
{
	dp[0][0]=1;
	for(int i=1; i<=m; i++)
		for(int j=0; j<=n; j++)
		{
			if(j-i>=0)
				dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
			else
				dp[i][j]=dp[i-1][j];
		}
}

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		solve();
		printf("%d %d\n", dp[m][n], dp[m-1][n]);
	}
	
	return 0;
}
