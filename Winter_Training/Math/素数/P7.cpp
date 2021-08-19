/*
加练题：Sum of Consecutive Prime Numbers_POJ 2739

*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=10007;

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

int n;

int main()
{
	int p=sieveErato(10007);
	while(scanf("%d", &n)!=EOF)
	{
		if(n==0)
			break;
		
		int maxp;
		for(int i=0;  i<p; i++)
		{
			if(prime[i]>=n)
			{
				maxp=i;
				break;
			}
		}
		int ans=0;
		for(int i=0; i<maxp; i++)
		{
			int re=n;
			int ind=i;
			while(re>0)
			{
				re-=prime[ind++];
				if(re==0)
				{
					ans++;
					break;
				}
			}
			if(is_prime[i]&&i>=n/2)
			{
				break;
			}
		}
		if(is_prime[n])
		{
			ans++;
		}
		printf("%d\n", ans);	
	}
	
	
	return 0;
}


