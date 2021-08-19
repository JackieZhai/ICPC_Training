/*
��ϰ�⣺Sumsets_POJ 2229
	dp���ƣ�
	���NΪ��������dp[N-1](ÿһ������1)��
	���NΪż������dp[N-1](ÿһ������1)+dp[N/2](ÿһ������ż��������2֮����N/2һһ��Ӧ)�� 
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1000007;
int dp[MAX_N], N;

int main()
{
	dp[1]=1;
	dp[2]=2;
	for(int i=3; i<=MAX_N; i++)
	{
		if(i%2==1)
			dp[i]=dp[i-1];
		else
			dp[i]=(dp[i-1]+dp[i/2])%(int)1e9;
	}
	scanf("%d", &N);
	printf("%d\n", dp[N]);
	
	
	return 0;
}
