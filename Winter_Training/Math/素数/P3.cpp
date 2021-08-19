/*
��ϰ�⣺Prime Number_AOJ 0009 
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1000007;

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
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		printf("%d\n", sieveErato(n));
	}
	return 0;
}
