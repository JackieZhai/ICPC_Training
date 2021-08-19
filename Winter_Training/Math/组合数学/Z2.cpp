/*
�����⣺Round Numbers_POJ 3252
	�ȴ���������
	�����iС������round��:
		��iСһλ��round��;
		��i������ͬ��round��(��Ҫ��i���бȽ�).
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
	bi[0]=0; //���ڴ�Ŷ���������λ��
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
	
	//�����nλ���ٵ������ע������������λһ����1 
	for(int i=1; i<bi[0]-1; i++)
		for(int j=i/2+1; j<=i; j++)
			ans+=c[i][j];
	
	//�����nλ����ȵ���� 
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

	//�����������Ǵ�� 
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
