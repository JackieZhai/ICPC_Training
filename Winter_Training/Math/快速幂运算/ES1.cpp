/*
���⣺Carmichael Numbers_UVa 10006 
	�����n<6500�������O(n)�����ݣ��ܵĸ��ӶȾ�ΪO(n^2)��������Ҫ��
	�����õ�Exponentiation by Squaring�����������֮һ��2^k-ary�㷨(O(log(n)))�� 
*/

#include <bits/stdc++.h>
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
