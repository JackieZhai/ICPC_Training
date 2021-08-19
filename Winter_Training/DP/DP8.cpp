/*
练习题：Dollar Dayz_POJ 3181 
	dp递推：
	dp[i]代表价格为i时得到的种类数。 
	dp进行num-i的叠加，
	但要注意会越界，需要进行高精度处理，十八位一组。 
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N=1007;
typedef long long ll;
const ll INF = 1000000000000000000; //必须展开 

ll dp[MAX_N];
ll dph[MAX_N];
int N, K;

int main()
{
	scanf("%d%d", &N, &K);
	
	memset(dp, 0, sizeof(dp));
	memset(dph, 0, sizeof(dph));
	
	dp[0]=1;
	for(int i=1; i<=K; i++)
	{
		for(int num=i; num<=N; num++)
		{
			dph[num]=dph[num]+dph[num-i]+(dp[num]+dp[num-i])/INF;
			dp[num]=(dp[num]+dp[num-i])%INF;
		}
	}
	
	if(dph[N]==0)
		printf("%lld\n", dp[N]);
	else
		printf("%lld%018lld\n", dph[N], dp[N]); //注意输出格式 
	
	
	return 0;
}
