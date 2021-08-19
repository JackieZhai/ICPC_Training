/*
加练题：Round Numbers_POJ 3252
	先打表组合数，
	再算比i小的所有round数:
		比i小一位的round数;
		和i长度相同的round数(需要和i进行比较).
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int bi[37];

int c[37][37];

void trans(int n)
{
	bi[0]=0; //用于存放二进制数的位数
	while(n!=0)
	{
		bi[++bi[0]]=n%2;
		n/=2;
	}	
}

int roundCal(int n)
{
	trans(n);
	int ans=0;
	
	//计算比n位数少的情况，注意二进制数最高位一定是1 
	for(int i=1; i<bi[0]-1; i++)
		for(int j=i/2+1; j<=i; j++)
			ans+=c[i][j];
	
	//计算和n位数相等的情况 
	int count0=0;
	for(int i=bi[0]-1; i>=1; i--)
	{
		if(bi[i]==1)
		{
			for(int j=(bi[0]+1)/2-(count0+1); j<=i-1; j++)
        	    ans+=c[i-1][j];
		}
		else
		{
			count0++;
		}
	}
	
	return ans;
}



int main()
{

	//组合数杨辉三角打表 
	for(int i = 0; i < 37; i++)
	{
		c[i][0] = 1;
		c[i][i] = 1;
	}
	for(int i = 1; i < 37; i++)
		for(int j = 1; j < i; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	
	
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", roundCal(b+1)-roundCal(a));
	
	
	return 0;
}
