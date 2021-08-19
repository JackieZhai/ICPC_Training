#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int M,T,N;   //M:题数  T:队数   N:冠军队至少做题数
double dp[1001][31][31];   //状态方程: dp[i][j][k]为第i队PASS前j题中的k题的概率

double p[1001][31];  //p[i][j]为第i队通过第j题的概率
double s[1001][31];  //s[i][j]为第i队在M题中至少PASS j题的概率

void ProTable(void)  //概率打表
{
	memset(dp,0.0,sizeof(dp));
	memset(s,0.0,sizeof(s));

	int i,j,k;
	for(i=1;i<=T;i++)  //逐队枚举
	{
		/*Initial*/

		dp[i][0][0]=1.0;

		for(j=1;j<=M;j++)
			dp[i][j][0]=dp[i][j-1][0]*(1-p[i][j]);

		/*Dp*/

		for(j=1;j<=M;j++)
			for(k=1;k<=j;k++)
				dp[i][j][k] = dp[i][j-1][k-1]*p[i][j] + dp[i][j-1][k]*(1-p[i][j]);

		s[i][0]=dp[i][M][0];
	    for(k=1;k<=M;k++)
			s[i][k]=s[i][k-1]+dp[i][M][k];
	}
	return;
}

int main()
{
	int i, j;
	while(cin>>M>>T>>N)
	{
		if(!M && !T && !N)
			break;

		/*Input*/

		for(i=1;i<=T;i++)
			for(j=1;j<=M;j++)
				cin>>p[i][j];

		/*Compute the Probability*/

		ProTable();

		double p1=1.0;
		for(i=1;i<=T;i++)
			p1*=(s[i][M]-s[i][0]);   //所有队至少做1题的概率

		double p2=1.0;
		for(i=1;i<=T;i++)
			p2*=(s[i][N-1]-s[i][0]); //所有队做的题数均在1~N-1之间的概率

		/*Output*/

		cout<<fixed<<setprecision(3)<<p1-p2<<endl;
		//每队至少解出一题 且 至少有一队(冠军队)能至少解出N道题的概率
	}
	return 0;
}
