/*
例题：最大化平均值 
	有n个物品的重量和价值分别是wi和vi。从中选出k个物品使得单位重量的价值最大。 
*/ 
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N=10007, INF=1e6+7;

int n, k;
int w[MAX_N], v[MAX_N];

double y[MAX_N]; //v-x*w

//判断是否满足条件 
bool C(double x)
{
	for(int i=0; i<n; i++)
	{
		y[i]=v[i]-x*w[i];
	}
	
	sort(y, y+n);
	
	//计算y数组从大到小前k个数的和
	double sum=0;
	for(int i=0; i<k; i++)
	{
		sum+=y[n-i-1];
	}
	return sum>=0;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++)
	{
		scanf("%d%d", &w[i], &v[i]);
	}
	
	double lb=0, ub=INF;
	for(int i=0; i<100; i++)
	{
		double mid=(lb+ub)/2;
		if(C(mid))
			lb=mid;
		else
			ub=mid;
	}
	
	printf("%.2f\n", ub);
	
	
	return 0;
}

