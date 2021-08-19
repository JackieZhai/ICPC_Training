/*
��ϰ�⣺Cow Acrobats_POJ 3045
	��С�����ֵ 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f, MAX_N=50007;

int N;
struct Node{
	int w, s;
}x[MAX_N];
bool cmp(const Node &a, const Node &b)
{
	return a.s+a.w<b.s+b.w; //�ж�˭�ڵ������������������ĺ;����� 
}

bool C(int dw)
{
	int sumw=0;
	for(int i=0; i<N; i++)
	{
		if(sumw-x[i].s>dw) //����������ΧԶԶ��������������dw���п����Ǹ��ģ�lb��Ϊ-INF 
			return false;
		sumw+=x[i].w;
	}
	
	return true;
	
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d%d", &x[i].w, &x[i].s);
	
	sort(x, x+N, cmp);
	
	int lb=-INF, ub=INF;
	while(ub-lb>1)
	{
		int mid=(ub+lb)/2;
		if(C(mid))
			ub=mid;
		else
			lb=mid;
		
	}
	
	printf("%d\n", ub);
	
	return 0;
}
