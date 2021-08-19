/*
练习题：Bound Found_POJ 2566
	此题的关键就是要把所有的前缀和排序
	这样才能进行尺取的内层循环 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=100007;
const int INF=0x3f3f3f3f;

int n, k;
int a[MAX_N];
pair<int, int> accu[MAX_N]; //保存下标的前缀和 
//pre-sum, index 

int getSum(int &res, int &s, int &t, int &T, int &from, int &to) //传入引用进行非全局变量操作 
{
	if(s>=t) //不合法 
		return -INF;
	
	int sum=accu[t].first-accu[s].first;
	if(abs(T-sum)<abs(T-res))
	{
		//更新答案
		res=sum;
		from=min(accu[s].second, accu[t].second);
		to=max(accu[s].second, accu[t].second); 
	}
	return sum;
}


int main()
{
	while(scanf("%d%d", &n, &k)!=EOF)
	{
		if(n==0 && k==0)
			break;
		
		for(int i=0; i<n; i++)
			scanf("%d", &a[i]);
		
		accu[0]=make_pair(0, 0); //下标从1开始
		for(int i=0; i<n; i++)
			accu[i+1]=make_pair(accu[i].first+a[i], i+1);
		sort(accu, accu+n+1);
		
		while(k--)
		{
			int T;
			scanf("%d", &T);
			
			int s=0, t=0, sum=-INF;
			int from, to, res=-INF;
			while(true)
			{
				while(t<n && sum<T)
				{
					sum=getSum(res, s, ++t, T, from, to);
				}
				if(sum<T)
					break;
				sum=getSum(res, ++s, t, T, from, to);
			}
			
			printf("%d %d %d\n", res, from+1, to);
		}
		
	}
	
	
	return 0;
}
