#include <bits/stdc++.h>
using namespace std;

const int MAX_N=2*10e6+5;

long long a[MAX_N];

bool cmp(long long a, long long b)
{
	return a>b;
}


int main()
{
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%I64d", &a[i]);
		
	sort(a, a+N, cmp);
	
	long long be=0;
	while(N!=0)
	{
		for(int i=0; i<N; i++)
			be+=a[i];
		
		N = N/4;
	}
	printf("%I64d\n", be);
	
	
	return 0;
}
