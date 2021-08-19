/*
练习题：Wooden Sticks_POJ 1065 
	把s按l进行升序排序后，问题就转化为求解w的LDS(最长下降子序列)了。 
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=5007;
int n;
struct Wood{
	int l,w;
}s[MAX_N];
bool cmp(const Wood& a, const Wood& b)
{
	if(a.l==b.l)
		return a.w<b.w;
	return a.l<b.l;
}
int dp[MAX_N];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d", &s[i].l, &s[i].w);
		}
		
		sort(s, s+n, cmp);
		
	
		//LDS
		fill(dp, dp+n, -1);
		for(int i=0; i<n; i++)
		{
			*lower_bound(dp, dp+n, s[i].w, greater<int>()) = s[i].w;
		}
		printf("%d\n", lower_bound(dp, dp+n, -1, greater<int>())-dp);
		
	}
	
	return 0;
}
