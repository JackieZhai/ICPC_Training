/*
01�������⣺ 
	���ڵݹ���õ�ʱ��(DFS)���м����ʱ���ظ������˺ܶ࣬�˷���ʱ�䡣 
	solve1();ʹ�ü��仯���飬���еݹ�(���仯����)�� 
	solve2();���е���(Recursion)��ֱ�Ӹ��ݵ���ʽͨ���򵥶���ѭ�������
	solve3();��ǰ�ߵĵ�����Ľ����ɽ�ʡ�ռ䣬��ʹ�ò��ÿ�������bug�� 
ע�������õ���������Ʒ�������Ȼ����Ҳ�ɣ�ֻ���dp��Ϊǰi����Ʒ�в�����j���ܼ�ֵ���ֵ�Ϳ��ԡ� 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 107, MAX_W = 10007;

int n, W;
int w[MAX_N], v[MAX_N]; 
int dp[MAX_N][MAX_W];

int rec(int i, int j)//��һ���������������ڼ������ڶ�����������ʣ�������� 
{
	//�Ѿ�������Ļ�����֮ǰ�Ľ�� 
	if(dp[i][j]>0)
		return dp[i][j];
	
	int res;
	if(i==n)//û��ʣ����Ʒ 
		res=0;
	else if(j<w[i])//û������ 
		res=rec(i+1, j);
	else//����������һ�� 
		res=max(rec(i+1, j), rec(i+1, j-w[i])+v[i]);
	
	//���������¼������֮�� 
	return dp[i][j]=res;
	
}

void solve1()
{
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec(0,W));
}

/*����ʽ�� 
dp[n][j]=0
dp[i][j]=
	dp[i+1][j] (j<w[i])	
	max(dp[i+1][j], dp[i+1][j-w[i]]+v[i]) (others)
*/

void solve2()
{
	//���ﲻҪ���ǳ�ʼ����ֻ����Ϊȫ����������ʡ�ԣ�
	//������������ݵ�ʱ��һ����Ҫ���ǣ�
	 
	for(int i=n-1; i>=0; i--)
		for(int j=0; j<=W; j++)
			if(j<w[i])
				dp[i][j]=dp[i+1][j];
			else
				dp[i][j]=max(dp[i+1][j], dp[i+1][j-w[i]]+v[i]);
				
	printf("%d\n", dp[0][W]);
	
}


int dp2[MAX_W];
void solve3()
{	
	for(int i=0; i<n; i++)
		for(int j=W; j>=w[i]; j--)
			dp2[j]=max(dp2[j], dp2[j-w[i]]+v[i])//�൱�����Ƶ��ۺ� 
	
	printf("%d\n", dp2[W]);
}

int main()
{
	scanf("%d%d", &n, &W);
	for(int i=0; i<n; i++)
		scanf("%d%d", &w[i], &v[i]);
	
	//solve1();
	//solve2();
	solve3();
	
	return 0;
}
