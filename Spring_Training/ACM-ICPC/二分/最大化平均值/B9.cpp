/*
练习题：K Best_POJ 3111
	最大化均值 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std;

const int MAX_N=100007, INF=0x3f3f3f3f;

int n, k;
int w[MAX_N], v[MAX_N];
int ans[MAX_N];

struct Node{  //为了排序之后保留数组下标所以设为结构体 
	double val;
	int ind;
}y[MAX_N]; // v-x*w
bool cmp(const Node &a, const Node &b)
{
	return a.val<b.val;
}


bool C(double x)
{
	for(int i=0; i<n; i++)
	{
		y[i].val=v[i]-x*w[i];
		y[i].ind=i;
	}
	sort(y, y+n, cmp);
	
	double sum=0;
	for(int i=0; i<k; i++)
	{
		sum+=y[n-i-1].val;
	}
	
	if(sum>=0)
	{
		for(int i=0; i<k; i++)
		{
			ans[i]=y[n-i-1].ind;
		}
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	while(scanf("%d%d", &n,  &k)!=EOF)
	{
		
		for(int i=0; i<n; i++)
			scanf("%d%d", &v[i], &w[i]);
		
		double lb=0, ub=INF;
		for(int i=0; i<50; i++)  //此处用100会超时，其实没必要那么大精度 
		{
			double mid=(lb+ub)/2;
			if(C(mid))
				lb=mid;
			else
				ub=mid;
		}
		
		for(int i=0; i<k; i++)
		{
			if(i!=0)
				printf(" ");
			printf("%d", ans[i]+1);
		}
		printf("\n");
	
	}
	
	
	return 0;
}
