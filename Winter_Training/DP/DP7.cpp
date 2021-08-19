/*
��ϰ�⣺Ant Counting_POJ 3046 
	dp���ƣ�
	���ؼ������ģ�壬ע��%M���⡣ 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1007, MAX_M=100007;
const int M=1000000;

/*
���ؼ���������⣺
	��n����Ʒ����i����Ʒ��ai������ͬ�������Ʒ���Ի������ֵ���ͬ����Ĳ��У�
	������ȡ��m�����ж�����ȡ�����󷽷���ģM��ֵ�� 
*/
int n, m;
int a[MAX_N];

int dp[MAX_N][MAX_M];

void solve()
{
	//һ������ȡ�÷�������ֻ��һ�� 
	for(int i=0; i<=n; i++)
		dp[i][0]=1;
	for(int i=0; i<n; i++)
		for(int j=1; j<=m; j++)
			if(j-1-a[i+1]>=0)
			//����ȡ�������£�Ҫ�����������Ľ�����ָ��� 
				dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-a[i+1]]+M)%M;
			else
				dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%M;
}

int main()
{
	int S, B;
	scanf("%d%d%d%d", &n, &m, &S, &B);
	for(int i=0; i<m; i++)
	{
		int buf;
		scanf("%d", &buf);
		a[buf]++;
	}
	
	solve();
	
	int ans=0;
	for(int i=S; i<=B; i++)
	{
		ans=(ans+dp[n][i])%M;
	}
	printf("%d\n", ans);
	
	return 0;
}



