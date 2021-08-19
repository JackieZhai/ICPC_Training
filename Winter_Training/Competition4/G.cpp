#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a, b;

const int MAX_N = 2e7+7; //�������� 

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
	int T;
	scanf("%d", &T);
	
	int amount = sieveErato(MAX_N);
	
	for(int k=1; k<=T; k++)
	{
		scanf("%d%d", &a, &b);
		if(a>b)
			swap(a, b);
		
		int ans=-1;
		for(int i=0; i<amount-1; i++)
		{
			if(prime[i]>=a&&prime[i+1]>=b&&(prime[i]-a==prime[i+1]-b))
			{
				ans=prime[i]-a;
				break;
			}
		}
		printf("Case %d: %d\n", k, ans);
		
		
	}
	
	
	
	
	return 0;
}
