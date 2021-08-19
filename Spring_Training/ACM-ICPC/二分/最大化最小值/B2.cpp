/*
例题：Aggressive cows_POJ 2456 
	最大化最小值 
*/ 
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N=100007, INF=1e9+7;
int N, M;
int x[MAX_N];

//判断是否满足条件 
bool C(int d)
{
	int last=0;
	for(int i=1; i<M; i++)
	{
		int crt=last+1;
		while(crt<N && x[crt]-x[last]<d)
		{
			crt++;
		}
		if(crt==N)
			return false;
		last=crt;
	}
	return true;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", &x[i]);
	
	//对x数组排序 
	sort(x, x+N);
	
	//初始化解的存在范围 
	int lb=0, ub=INF;
	
	while(ub-lb>1)
	{
		int mid=(lb+ub)/2;
		if(C(mid))
			lb=mid;
		else
			ub=mid;
	}
	
	printf("%d\n", lb);
	
	return 0;
}
