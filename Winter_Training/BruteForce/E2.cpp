/*
��ϰ�⣺Backward Digit Sums_POJ 3187

��ΪҪ�ֵ���С�����������������next_permutation()�󷨺ã� 
���⣬�ڼ���sumֵ��ʱ�򣬻�����ֻ�ѳ˷������ۺͼ��㣬����ٳˡ� 
*/
#include <cstdio> 
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	long long sum;
	scanf("%d%lld", &n, &sum);
	//�߽紦���� 
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	int a[10];
	for(int i=0; i<n; i++)
		a[i]=i+1;
	do{
		long long suml[10];
		for(int i=0; i<n-1; i++)
			suml[i]=a[i]+a[i+1];
		for(int i=0; i<n-2; i++)
		{
			for(int j=0; j<=n-2-i; j++)
			{
				suml[j]=suml[j]+suml[j+1];
			}
		}
		
		if(suml[0]==sum)
		{
			printf("%d",a[0]);
			for(int i=1; i<n; i++)
				printf(" %d", a[i]);
			printf("\n");
			break;
		}
	}while(next_permutation(a, a+n));

	return 0;
} 
