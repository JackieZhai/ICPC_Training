/*
��ϰ�⣺Dollar Dayz_POJ 3181 
	dp���ƣ�
	dp[i]����۸�Ϊiʱ�õ����������� 
	dp����num-i�ĵ��ӣ�
	��Ҫע���Խ�磬��Ҫ���и߾��ȴ���ʮ��λһ�顣 
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N=1007;
typedef long long ll;
const ll INF = 1000000000000000000; //����չ�� 

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
		printf("%lld%018lld\n", dph[N], dp[N]); //ע�������ʽ 
	
	
	return 0;
}
