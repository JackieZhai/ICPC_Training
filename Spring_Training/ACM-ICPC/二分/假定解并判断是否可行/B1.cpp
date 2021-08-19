/*
���⣺Cable master_POJ 1064 
	�ٶ�һ���Ⲣ�ж��Ƿ���� 
*/ 
#include <cstdio>
#include <cmath>
using namespace std;

const int MAX_N=10007, INF=100007;
int N, K;
double L[MAX_N];

//�ж��Ƿ��������� 
bool C(double x)
{
	int num=0;
	for(int i=0; i<N; i++)
	{
		num+=(int)(L[i]/x);
	}
	return num>=K;
}

int main()
{
	scanf("%d%d",  &N, &K);
	for(int i=0; i<N; i++)
		scanf("%lf", &L[i]);
	
	//��ʼ����ķ�Χ 
	double lb=0, ub=INF;
	
	//�ظ�ѭ����ֱ����ķ�Χ�㹻С
	for(int i=0; i<100; i++)
	{
		double mid=(lb+ub)/2;
		if(C(mid))
			lb=mid;
		else
			ub=mid;
	}
	
	printf("%.2lf\n", floor(ub*100)/100); //C++,lf; G++,f
	
	return 0;
}
