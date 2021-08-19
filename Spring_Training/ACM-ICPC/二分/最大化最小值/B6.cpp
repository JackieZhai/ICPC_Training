/*
练习题：Drying_POJ 3104
	最小化最大值 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f, MAX_N=100007;

int N, M;
long long x[MAX_N];

bool C(int minu)
{
	int coun=0;
	for(int i=0; i<N; i++)
	{
		if(x[i]-minu>0)
		{					   //题意是烘干机烘干的时候不会自然掉水 
			int xre=x[i]-minu; //转化为烘干机每分钟掉M-1水，这样所有都是自然烘干掉1水了 
			if(xre%(M-1)==0)
				coun+=xre/(M-1);
			else
				coun+=xre/(M-1)+1;
			
			if(coun>minu)      //需要把判断放在for里面，要不然coun会爆int 
				return false;
		}
	}
	
	return true;
}

int main()
{
	scanf("%d",  &N);
	for(int i=0; i<N; i++)
		scanf("%lld", &x[i]);
	scanf("%d", &M);
	
	if(M==1)
	{
		int ans=0;
		for(int i=0; i<N; i++)
			if(ans<x[i])
				ans=x[i];
		printf("%d\n", ans);
	}
	else
	{
	
		int lb=0, ub=INF;
		while(ub-lb>1)
		{
			int mid=(ub+lb)/2;
			if(C(mid))
				ub=mid;
			else
				lb=mid;
		}
		
		printf("%d\n", ub);
		
	}
	
	return 0;
}
