long long int MOD = 1e9+7;
long long int c[2010][2010];


	for(int i = 0; i < 2005; i++)
	{
		c[i][0] = 1;
		c[i][i] = 1;
	}
	for(int i = 1; i < 2005; i++)
		for(int j = 1; j < i; j++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
