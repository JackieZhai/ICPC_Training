/*
部分和问题： 
	从整数a1, a2...中判断是否可以从中选出若干数，使得他们的和恰好为k。 
*/

#include <bits/stdc++.h>
using namespace std;


int a[1000];
int n, k;

bool dfs(int i, int sum)
{
	//已经遍历到末尾 
	if(i == n)
		return sum==k;
	//不加入a[i] 
	if(dfs(i+1, sum))
		return true;//同对同错 
	//加入a[i] 
	if(dfs(i+1, sum+a[i]))
		return true;//同对同错
	//不管怎样都不行 
	return false;
	
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	
	if(dfs(0, 0))
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}
