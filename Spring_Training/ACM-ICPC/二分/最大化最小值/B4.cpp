/*
练习题：River Hopscotch_POJ 3258 
	最大化最小值，将去掉M个石头转化为留下N-M个石头 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f, MAX_N=50007;

int N, M;
int x[MAX_N];

//判断最小距离d的情况下能不能做成 
bool C(int d)
{
	int last=0;
	for(int i=1; i<M; i++)
	{
		int crt=last+1;
		while(crt<N && x[crt]-x[last]<d)
			crt++;
		if(crt==N)
			return false;
		last=crt;
	}
	return true;
}


int main()
{
	int L;
	scanf("%d%d%d", &L, &N, &M);
	N+=2;
	M=N-M;
	x[0]=0;
	x[N-1]=L;
	for(int i=1; i<N-1; i++)
		scanf("%d", &x[i]);
	
	
	
	//最开始对x进行排序
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
