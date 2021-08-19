/*
	找规律，两次简单排序。 
*/

#include <bits/stdc++.h>
using namespace std;

long long a[807], b[807];
int n;

int main()
{
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	
	
	int T;
	scanf("%d", &T);
	for(int k=1; k<=T; k++)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%I64d", &a[i]);
		for(int i=0; i<n; i++)
			scanf("%I64d", &b[i]);	
		
		sort(a, a+n);
		sort(b, b+n);
		
		long long ans=0;
		for(int i=0; i<n; i++)
		{
			ans+=a[i]*b[n-i-1];
		}
		printf("Case #%d: %I64d\n", k, ans);
	}
	
	
	return 0;
}
