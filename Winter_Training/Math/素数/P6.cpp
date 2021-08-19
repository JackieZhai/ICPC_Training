/*
练习题：Semi-prime H-numbers_POJ 3292 
*/

#include<string>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAX_N=1000007;

int H;
bool is_semiprime[MAX_N];
int semiprimecount[MAX_N];

//埃氏筛法(Sieve of Eratosthenes)
int prime[MAX_N]; //第i个素数，此为存放素数的数组 
bool is_prime[MAX_N]; //is_prime[]为true时为素数
int p=0;
//返回n以内素数的个数
void sieveErato(int n)
{
	for(int i=1; i<=n; i+=4)
		is_prime[i]=true;
	is_prime[1]=false;
	for(int i=5; i<=n; i+=4)
	{
		if(is_prime[i])
		{
			prime[p++]=i;
			for(int j=5*i; j<=n; j+=i*4)
				is_prime[j]=false;
		}
	}
}


int main()
{
	sieveErato(MAX_N);
	bool flag=false;
	for(int i=0; i<p; i++)
	{
		for(int j=i; j<p; j++)
		{
			long long mul=prime[i];
			mul*=prime[j];
			if(mul>MAX_N||mul<0)
				break;
			is_semiprime[mul]=true;
		}
	}
	int count=0;
	for(int i=21; i<=MAX_N; i++)
	{
		if(is_semiprime[i])
		{
			count++;
		}
		semiprimecount[i]=count;
	}
	while(scanf("%d", &H)!=EOF)
	{
		if(H==0)
			break;
		printf("%d ", H);
		printf("%d\n", semiprimecount[H]);
		
	}
	
	return 0;
}

//1000001:105753

