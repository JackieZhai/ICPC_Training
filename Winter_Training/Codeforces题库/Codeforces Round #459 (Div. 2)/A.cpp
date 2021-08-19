#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1007;
int memo[MAX_N];

int fib (int n)
{
	if (n <= 1)
		return n;
	if (memo[n] != 0)
		return memo[n];
	return (memo[n] = fib(n - 1) + fib(n - 2));
}

int main()
{
	int n, i=1, e=1;
	scanf("%d", &n);
	bool flag=false;
	while(1)
	{
		i++;
		int j=fib(i);
		for(int k=e; k<j; k++)
		{
			
			if(k>n)
			{
				flag=true;
				break;
			}
			printf("o");
		}
		if(j>n)
		{
			flag=true;
		}
		if(flag)
		{
			break;
		}
		printf("O");
		e=j+1;
		
	}
	printf("\n");
	return 0;
}
