#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N=2607;

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

bool ans[97];

int main()
{
	sieveErato(MAX_N);
	for(int i=0; i<=89; i++)
	{
		int t=(i-39)*(i-39)+(i-39)+41;
		ans[i]=is_prime[t];
	}
	
	int x, y;
	while(scanf("%d%d", &x, &y)!=EOF)
	{
		if(x==0&&y==0)
			break;
		
		bool flag=true;
		for(int i=x+39; i<=y+39; i++)
			if(ans[i]==false)
			{
				flag=false;
				break;
			}
		
		if(flag)
		{
			printf("OK\n");
		}
		else
		{
			printf("Sorry\n");
		}
	}
	
	
	
	return 0;
}

