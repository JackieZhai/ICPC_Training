#include <cstdio>
#include <iostream>
using namespace std;

long long int MOD = 1e9+7;
long long int c[37][37];


int main()
{

	for(int i = 0; i < 37; i++)
	{
		c[i][0] = 1;
		c[i][i] = 1;
	}
	for(int i = 1; i < 37; i++)
		for(int j = 1; j < i; j++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, r;
		scanf("%d%d", &n, &r);
		printf("%I64d\n", c[n][r]);
	}

			
	return 0;
}
