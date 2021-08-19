/*
��ȫ�������⣺ 
	�����01�������⣬�������ÿ����Ʒ������ѡ����Ρ�
	�����ʽ����ת�������Ӷ���ΪO(nW)�� 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 107, MAX_W = 10007;

int n, W;
int w[MAX_N], v[MAX_N]; 
int dp[MAX_N][MAX_W];

void solve()
{
	for(int i=0; i<n; i++)
		for(int j=0; j<=W; j++)
			if(j<w[i])
				dp[i+1][j]=dp[i][j];
			else
				dp[i+1][j]=max(dp[i][j], dp[i+1][j-w[i]]+v[i]);
	
	printf("%d\n", dp[n][W]);
}

int main()
{
	scanf("%d%d", &n, &W);
	for(int i=0; i<n; i++)
		scanf("%d%d", &w[i], &v[i]);
	
	solve();
	
	return 0;
}
