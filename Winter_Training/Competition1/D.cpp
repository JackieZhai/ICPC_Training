/*
The first line contains a single integer n (1<=n<=3*10e5).
The second line contains n integers a1, a2, ..., an (1<=ai<=10e6)--the initial group that is given to Toastman.

Why should we use long long int in a[maxn]???

*/


#include <bits/stdc++.h>
using namespace std;

const int maxn = 3*10e5+5;
long long int a[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%I64d", &a[i]);
	if(n==1)
	{
		printf("%I64d\n", a[0]);
		return 0;
	}
	sort(a,a+n);
	long long int sum=0;
	sum += n*a[n-1]+n*a[n-2];
	for(int i = 0; i <= n-3; i++)
	{
		sum += (2+i)*a[i];
	}
	printf("%I64d\n", sum);
	
	return 0;
}
