/*
��ϰ�⣺Raising Modulo Numbers_POJ 1995 
*/

#include <cstdio>
#include <iostream>
using namespace std;

//���������� 
typedef long long ll;
ll mod_pow(ll x, ll n, ll mod)
{
	ll res=1;
	while(n>0)
	{
		if(n&1)
			res=res*x%mod; //������������λΪ1�������x^(2^i) 
		x=x*x%mod; //��xƽ�� 
		n>>=1;
	}
	return res;
}


int main()
{
	int T, M;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &M);
		int H;
		scanf("%d", &H);
		ll ans=0;
		while(H--)
		{
			int A, B;
			scanf("%d%d", &A, &B);
			ans+=mod_pow(A, B, M);
			ans%=M;
		}
		printf("%lld\n", ans);
	}
	return 0;
}





