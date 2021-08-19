/*
练习题：GCD and LCM_AOJ 0005
	此题拓展了LCM(the least common multiple)的求法。 
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
		printf("%lld\n", a/g*b);//注意这里先做除法！ 
		
	}
	
	return 0;
}
