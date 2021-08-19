#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

int M,T,N;   //M:����  T:����   N:�ھ�������������
double dp[1001][31][31];   //״̬����: dp[i][j][k]Ϊ��i��PASSǰj���е�k��ĸ���

double p[1001][31];  //p[i][j]Ϊ��i��ͨ����j��ĸ���
double s[1001][31];  //s[i][j]Ϊ��i����M��������PASS j��ĸ���

void ProTable(void)  //���ʴ��
{
	memset(dp,0.0,sizeof(dp));
	memset(s,0.0,sizeof(s));

	int i,j,k;
	for(i=1;i<=T;i++)  //���ö��
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
			p1*=(s[i][M]-s[i][0]);   //���ж�������1��ĸ���

		double p2=1.0;
		for(i=1;i<=T;i++)
			p2*=(s[i][N-1]-s[i][0]); //���ж�������������1~N-1֮��ĸ���

		/*Output*/

		cout<<fixed<<setprecision(3)<<p1-p2<<endl;
		//ÿ�����ٽ��һ�� �� ������һ��(�ھ���)�����ٽ��N����ĸ���
	}
	return 0;
}
