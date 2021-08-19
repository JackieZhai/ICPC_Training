/*
01背包问题： 
	由于递归调用的时候(DFS)进行计算的时候重复计算了很多，浪费了时间。 
	solve1();使用记忆化数组，进行递归(记忆化搜索)； 
	solve2();进行递推(Recursion)，直接根据递推式通过简单二重循环算出。
	solve3();对前者的单数组改进，可节省空间，但使用不好可能留下bug。 
注：此例用的是逆向递推方法，当然正向也可，只需把dp变为前i个物品中不超过j的总价值最大值就可以。 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 107, MAX_W = 10007;

int n, W;
int w[MAX_N], v[MAX_N]; 
int dp[MAX_N][MAX_W];

int rec(int i, int j)//第一个参数代表挑到第几个；第二个参数代表还剩多少容量 
{
	//已经计算过的话调用之前的结果 
	if(dp[i][j]>0)
		return dp[i][j];
	
	int res;
	if(i==n)//没有剩余物品 
		res=0;
	else if(j<w[i])//没法挑走 
		res=rec(i+1, j);
	else//挑不挑都试一下 
		res=max(rec(i+1, j), rec(i+1, j-w[i])+v[i]);
	
	//并将结果记录到数组之中 
	return dp[i][j]=res;
	
}

void solve1()
{
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec(0,W));
}

/*递推式： 
dp[n][j]=0
dp[i][j]=
	dp[i+1][j] (j<w[i])	
	max(dp[i+1][j], dp[i+1][j-w[i]]+v[i]) (others)
*/

void solve2()
{
	//这里不要忘记初始化，只是因为全局数组所以省略；
	//当处理多组数据的时候一定不要忘记！
	 
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
			dp2[j]=max(dp2[j], dp2[j-w[i]]+v[i])//相当于正推的累和 
	
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
