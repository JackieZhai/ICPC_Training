/*
��ϰ�⣺GCD and LCM_AOJ 0005
	������չ��LCM(the least common multiple)���󷨡� 
*/ 

#include <cstdio>
#include <iostream>
using namespace std;

long long a, b;

long long gcd(long long a, long long b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	while(scanf("%lld%lld", &a, &b)!=EOF)
	{
		long long g=gcd(a, b);
		printf("%lld ", g);
		printf("%lld\n", a/g*b);//ע���������������� 
		
	}
	
	return 0;
}
