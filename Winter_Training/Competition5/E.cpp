#include <bits/stdc++.h> 
using namespace std;

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

ll n;

int main()
{
	int T;
	scanf("%d\n", &T);
	while(T--)
	{
		scanf("%I64d", &n);
		printf("%I64d\n", mod_pow(n, n, 10));
	}
	
	
	return 0;
}
