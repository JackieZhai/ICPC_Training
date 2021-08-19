/*
例题：Cable master_POJ 1064 
	假定一个解并判断是否可行 
*/ 
#include <cstdio>
#include <cmath>
using namespace std;

const int MAX_N=10007, INF=100007;
int N, K;
double L[MAX_N];

//判断是否满足条件 
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
	
	//初始化解的范围 
	double lb=0, ub=INF;
	
	//重复循环，直到解的范围足够小
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
