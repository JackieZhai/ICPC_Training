/*
练习题：Dropping tests_POJ 2976
	最大化均值 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std;

const int MAX_N=1007, INF=1.01;
typedef long long ll;

int n, k;
ll w[MAX_N], v[MAX_N];

double y[MAX_N]; // v-x*w

bool C(double x)
{
	for(int i=0; i<n; i++)
		y[i]=v[i]-x*w[i];
	sort(y, y+n);
	
	double sum=0;
	for(int i=0; i<k; i++)
	{
		sum+=y[n-i-1];
	}
	
	return sum>=0;
}

int main()
{
	while(scanf("%d%d", &n,  &k)!=EOF)
	{
		if(n==0&&k==0)
			break;
		
		k=n-k; //转化drop为resume 
		for(int i=0; i<n; i++)
			scanf("%lld", &v[i]);
		for(int i=0; i<n; i++)
			scanf("%lld", &w[i]);
		
		double lb=0, ub=INF;
		for(int i=0; i<100; i++)
		{
			double mid=(lb+ub)/2;
			if(C(mid))
				lb=mid;
			else
				ub=mid;
		}
		
		printf("%d\n", (int)floor(lb*100+0.5)); //floor返回的是double！ 
	
	}
	
	
	return 0;
}
