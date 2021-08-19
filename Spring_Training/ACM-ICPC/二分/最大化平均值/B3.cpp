/*
���⣺���ƽ��ֵ 
	��n����Ʒ�������ͼ�ֵ�ֱ���wi��vi������ѡ��k����Ʒʹ�õ�λ�����ļ�ֵ��� 
*/ 
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N=10007, INF=1e6+7;

int n, k;
int w[MAX_N], v[MAX_N];

double y[MAX_N]; //v-x*w

//�ж��Ƿ��������� 
bool C(double x)
{
	for(int i=0; i<n; i++)
	{
		y[i]=v[i]-x*w[i];
	}
	
	sort(y, y+n);
	
	//����y����Ӵ�Сǰk�����ĺ�
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

