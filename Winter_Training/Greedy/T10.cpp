/*
练习题：Stripies_POJ 1862
	每次都选最大的两项进行碰撞(开根运算)。 
	 
*/
#include <cstdio>
#include <cmath>
#include <algorithm> 
using namespace std;

double a[107];


double cal(double a, double b)
{
	return 2*sqrt(a*b);
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%lf", &a[i]);
	
	
	double ans;
	int num=N;
	for(int i=0; i<N-1; i++)
	{
		sort(a, a+num);
		a[num-2]=cal(a[num-1], a[num-2]);
		num--;
	}
		
	printf("%.3lf\n", a[0]);
	
	//%lf G++ 4.8 以后才支持，用C++就可AC。 
	
	return 0;
}
