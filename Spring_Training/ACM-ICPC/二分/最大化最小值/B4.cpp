/*
��ϰ�⣺River Hopscotch_POJ 3258 
	�����Сֵ����ȥ��M��ʯͷת��Ϊ����N-M��ʯͷ 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f, MAX_N=50007;

int N, M;
int x[MAX_N];

//�ж���С����d��������ܲ������� 
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
	
	
	
	//�ʼ��x��������
	sort(x, x+N);
	
	//��ʼ����Ĵ��ڷ�Χ
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
