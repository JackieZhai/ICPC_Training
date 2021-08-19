/*
	此题如果暴力会TLE，如果记录结果会MLE；
	只能运用威尔逊定理，知道n>4时，如果是素数结果为n-1，如果不是结果为0。 
	另外，埃氏筛法也会MLE。 
*/ 
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
			return false;
	}
	return n!=1; //1是例外 
}

int main()
{	
	int T;
	scanf("%d", &T);

	
	while(T--)
	{
		int n;
		scanf("%d", &n);
		if(n==1)
			printf("0\n");
		else if(n==2)
			printf("1\n");
		else if(n==3||n==4)
			printf("2\n");
		else
		{
			if(is_prime(n))
				printf("%d\n", n-1);
			else
				printf("0\n");			
		}
	}
	
	
	
	return 0;
}
