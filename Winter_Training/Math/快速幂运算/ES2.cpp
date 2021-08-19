/*
��ϰ�⣺Pseudoprime numbers_POJ 3641 
*/

#include <cstdio>
#include <iostream>
using namespace std;

//���Բ���
bool is_prime(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
			return false;
	}
	return n!=1; //1������ 
}


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
