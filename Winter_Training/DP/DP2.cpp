/*
练习题：Sumsets_POJ 2229
	dp递推：
	如果N为奇数，则dp[N-1](每一个都加1)；
	如果N为偶数，则dp[N-1](每一个都加1)+dp[N/2](每一个都是偶数，除以2之后与N/2一一对应)。 
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
