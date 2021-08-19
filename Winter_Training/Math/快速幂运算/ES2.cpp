/*
练习题：Pseudoprime numbers_POJ 3641 
*/

#include <cstdio>
#include <iostream>
using namespace std;

//素性测试
bool is_prime(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
			return false;
	}
	return n!=1; //1是例外 
}


//快速幂运算 
typedef long long ll;
ll mod_pow(ll x, ll n, ll mod)
{
	ll res=1;
	while(n>0)
	{
		if(n&1)
			res=res*x%mod; //如果二进制最低位为1，则乘上x^(2^i) 
		x=x*x%mod; //将x平方 
		n>>=1;
	}
	return res;
}


int main()
{
	int n,a;
	while(scanf("%d%d", &n, &a)!=EOF)
	{
		if(n==0&&a==0)
			break;
		if(mod_pow(a, n, n)!=a)
		{
			printf("no\n");
		}
		else if(is_prime(n))
			printf("no\n");
		else
			printf("yes\n");
	}
	
	return 0;
}
