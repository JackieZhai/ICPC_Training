/*
加练题：Dirichlet's Theorem on Arithmetic Progressions_POJ 3006
	FYI, it is known that the result is always less than 106 (one million) under this input condition.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=1e6+7;

//埃氏筛法(Sieve of Eratosthenes)
int prime[MAX_N]; //第i个素数，此为存放素数的数组 
bool is_prime[MAX_N]; //is_prime[]为true时为素数

//返回n以内素数的个数
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
	int p=sieveErato(MAX_N);
	
	int a, d, n;
	while(scanf("%d%d%d", &a, &d, &n)!=EOF)
	{
		if(a==0&&d==0&&n==0)
			break;
		
		int num=a, count=0;
		while(true)
		{
			if(is_prime[num])
				count++;
			if(count==n)
				break;
			num+=d;
		}
		printf("%d\n", num);
	}
	
	
	
	return 0;
}
