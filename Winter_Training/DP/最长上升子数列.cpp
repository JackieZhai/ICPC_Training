/*
�����������(LIS, Longest Increasing Subsequence)���⣺ 
	solve1()������dp[i]Ϊ��aiΪĩβ������������еĳ��ȣ�O(n^2)��
	solve2()������dp[i]Ϊ����Ϊi+1��������������ĩβԪ�ص���Сֵ��
		����֪������dp[]����INF֮���ǵ��������ģ��������ö��������õ������O(nlogn)�� 
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1007, INF=0x3f3f3f3f;

int n;
int a[MAX_N];

int dp[MAX_N];

void solve1()
{
	int res=0;
	for(int i=0; i<n; i++)
	{
		dp[i]=1;
		for(int j=0; j<i; j++)
		{
			if(a[j]<a[i])
				dp[i]=max(dp[i], dp[j]+1);
		}
		res=max(res, dp[i]);
	}
	printf("%d\n", res);
}

void solve2()
{
	fill(dp, dp+n, INF); //INF ��Ϊ -1 ��ΪLDS 
	for(int i=0; i<n; i++)
	{
		*lower_bound(dp, dp+n, a[i]) = a[i]; //, greater<int>() ��ΪLDS; ��Ϊupper�������½��� 
	}
	printf("%d\n", lower_bound(dp, dp+n, INF)-dp); //, greater<int>(); INF ��Ϊ -1 ��ΪLDS 
}


int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	//solve1();
	solve2();
	
	return 0;
}


