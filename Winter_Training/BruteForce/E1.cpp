/*
练习题：Smallest Difference_POJ 2718

此题用的是next_permutation()的穷举，关键在于掌握mid的用法，使得不用拆分为两个数组；
另外，此题还可以用贪心算法求解：
1、当给的数有偶数个时，去中间两个数为两数首位，让首位小的后面最大、让首位大的后面最小；
2、当给的数有奇数个时，让位数多的最小、位数少的最大。 
*/
#include <cstdio> 
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int a[10],T;
	scanf("%d", &T);
	getchar();
	while(T--)
	{
		int n=0;
		memset(a, 0, sizeof(a));
		string st;
		getline(cin, st);
		for(int i=0; i!=st.size(); i++)
			if(st[i]<='9'&&st[i]>='0')
			{
				a[n++]=st[i]-'0';
			}
		
		//给的数据已经排好序，不过若没有排序，则用sort()排一下即可 
		if(n==2)
		{
			printf("%d\n", a[1]-a[0]);
			continue;
		}
		while(a[0]==0)
			next_permutation(a, a+n);
		int mid=(n+1)/2;
		int ans=999999999;
		do
		{
			if(a[mid]==0)
				continue;
			int c=0, b=0;
			for(int i=0; i<mid; i++)
				c=c*10+a[i];
			for(int i=mid; i<n; i++)
				b=b*10+a[i];
			if(ans>abs(c-b))
				ans=abs(c-b);
		}while(next_permutation(a, a+n));
		printf("%d\n", ans);
	}
	
	return 0;
}
