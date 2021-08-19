/*
例题：Carmichael Numbers_UVa 10006 
	此题的n<6500，如果用O(n)计算幂，总的复杂度就为O(n^2)，不符合要求；
	这里用到Exponentiation by Squaring的最基本方法之一：2^k-ary算法(O(log(n)))。 
*/

#include <bits/stdc++.h>
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
	int n;
	scanf("%d", &n);
	for(int i=1; i<n; i++)
	{
		if(mod_pow(i, n, n)!=i)
		{
			printf("NO\n");
			return 0;
		}
	}
	if(!is_prime(n))
		printf("YES\n");
	else
		printf("NO\n");
	
	
	return 0;
}
