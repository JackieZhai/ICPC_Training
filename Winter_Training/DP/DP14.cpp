/*
�����⣺Balance_POJ 1837
	����ת��Ϊ01��������
	״̬����dp[i][ j+ w[i]*c[k] ]= ��(dp[i-1][j])
	��ʼ����dp[0][7500] = 1;   �����κ�����ʱ����ƽ�⣬��Ϊһ������
 
*/
#include <cstdio>
#include <cstring>
using namespace std;

int dp[27][15007];
int n, g;
int c[27], w[27];

int main()
{
	scanf("%d%d", &n, &g);
	for(int i=1;i<=n; i++)
		scanf("%d", &c[i]);
	for(int i=1; i<=g; i++)
		scanf("%d", &w[i]);
	
	memset(dp, 0, sizeof(dp));
	dp[0][7500]=1;
	
	for(int i=1; i<=g; i++)
		for(int j=0; j<=15000; j++)
		{
			if(dp[i-1][j]!=0)
			{
				for(int k=1; k<=n; k++)
					dp[i][j+w[i]*c[k]]+=dp[i-1][j];
			}
		}
	
	printf("%d\n", dp[g][7500]);
	
	return 0;
}
