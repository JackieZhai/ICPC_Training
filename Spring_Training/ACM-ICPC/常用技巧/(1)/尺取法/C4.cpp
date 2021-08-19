/*
��ϰ�⣺Sum of Consecutive Prime Numbers_POJ 2739
	��ϰ���ɸ����һ���� 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=10007;

//����ɸ��(Sieve of Eratosthenes)
int prime[MAX_N]; //��i����������Ϊ������������� 
bool is_prime[MAX_N]; //is_prime[]ΪtrueʱΪ����

//����n���������ĸ���
int sieveErato(int n)
{
	int p=0;
	for(int i=0; i<=n; i++)
		is_prime[i]=true;
	is_prime[0]=false;
	is_prime[1]=false;
	for(int i=2; i<=n; i++)
	{
		if(is_prime[i])
		{
			prime[p++]=i;
			for(int j=2*i; j<=n; j+=i)
				is_prime[j]=false;
		}
	}
	return p;
}




int main()
{
	int P=sieveErato(MAX_N);
	int num;
	while(scanf("%d", &num)!=EOF)
	{
		if(num==0)
			break;
		
		int s=0, t=0, sum=0;
		int res=0;
		while(true)
		{
			while(t<P && sum<num)
			{
				sum+=prime[t++];
			}
			if(sum<num)
				break;
			if(sum==num)
				res++;
			sum-=prime[s++];
		}
		
		printf("%d\n", res);
		
		
		
	}
	
	
	return 0;
}
