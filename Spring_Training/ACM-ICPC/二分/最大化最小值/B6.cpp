/*
��ϰ�⣺Drying_POJ 3104
	��С�����ֵ 
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
		{					   //�����Ǻ�ɻ���ɵ�ʱ�򲻻���Ȼ��ˮ 
			int xre=x[i]-minu; //ת��Ϊ��ɻ�ÿ���ӵ�M-1ˮ���������ж�����Ȼ��ɵ�1ˮ�� 
			if(xre%(M-1)==0)
				coun+=xre/(M-1);
			else
				coun+=xre/(M-1)+1;
			
			if(coun>minu)      //��Ҫ���жϷ���for���棬Ҫ��Ȼcoun�ᱬint 
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
