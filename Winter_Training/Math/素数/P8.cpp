/*
�����⣺Goldbach's Conjecture_POJ 2262
	Ŀǰ��֤�����˸�°ͺղ����Ǵ��LOL. 
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
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
	int p = sieveErato(MAX_N);
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		if(n==0)
			break;
		
		int maxp;
		for(int i=0; i<p; i++)
		{
			if(prime[i]>n)
			{
				maxp=i;
				break;
			}
		}
		int l=0, r=maxp-1;
		while(true)
		{
			if(prime[l]+prime[r]==n)
			{
				break;
			}
			else if(prime[l]+prime[r]>n)
			{
				r--;
			}
			else
			{
				l++;
			}
		}
		printf("%d = %d + %d\n", n, prime[l], prime[r]);	
	}
	
	return 0;
}


