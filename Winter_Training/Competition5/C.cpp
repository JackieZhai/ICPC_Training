#include <bits/stdc++.h> 
using namespace std;

int n, m;

long long int MOD = 1e9+7;
long long int c[1007][1007];

int main()
{
	int T;
	scanf("%d", &T);
	//Ñî»ÔÈý½Ç 
	for(int i = 0; i < 1007; i++)
	{
		c[i][0] = 1;
		c[i][i] = 1;
	}
	for(int i = 1; i < 1007; i++)
		for(int j = 1; j < i; j++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
		
	while(T--)
	{
		scanf("%d%d", &n, &m);
		int ma=max(n, m);
		int mi=min(n, m);
		
		printf("%d\n", c[ma][ma-mi]);
		
	}
	
	
	return 0;
}
