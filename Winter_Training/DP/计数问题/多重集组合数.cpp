/*
���ؼ���������⣺
	��n����Ʒ����i����Ʒ��ai������ͬ�������Ʒ���Ի������ֵ���ͬ����Ĳ��У�
	������ȡ��m�����ж�����ȡ�����󷽷���ģM��ֵ�� 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

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
