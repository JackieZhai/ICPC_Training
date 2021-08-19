/*
��ϰ�⣺Milking Time_POJ 3616
	dp���ƣ�
	��ͨ��.st���� 
	dp[]��ʾ�����i��ʱ��κ����ļ���������ʼ��Ϊ��i�μ�������
	������㣺val[j].en<=val[i].st(0<=j<i) 
	dp[i] = max(dp[i], dp[j]+val[i].ef);
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=1000007, MAX_M=1007;

int N, M, R;
struct Node{
	int st, en, ef;
};

bool cmp(const Node& a, const Node& b)
{
	return a.st<b.st;
}

Node val[MAX_M];
int dp[MAX_M];
int ans=0;

int main()
{
	scanf("%d%d%d", &N, &M, &R);
	for(int i=0; i<M; i++)
	{
		scanf("%d%d%d", &val[i].st, &val[i].en, &val[i].ef);
		val[i].en+=R;
	}
	
	sort(val, val+M, cmp);
	
	dp[0]=val[0].ef;
	for(int i=1; i<M; i++)
	{
		dp[i]=val[i].ef;
		for(int j=0; j<i; j++)
		{
			if(val[j].en<=val[i].st)
			{
				dp[i]=max(dp[i], dp[j]+val[i].ef);
			}
		}
	}
	
	for(int i=0; i<M; i++)
	{
		if(ans<dp[i])
			ans=dp[i];
	}
	printf("%d\n", ans);
	

	return 0;
}
