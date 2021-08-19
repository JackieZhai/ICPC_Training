/*
���⣺Subsequence_POJ 3061
	ע���ȸ���t���ڸ���s 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=100007;

int N, S;
int a[MAX_N];
int sum[MAX_N];


int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &S);
		for(int i=0; i<N; i++)
		{
			scanf("%d", &a[i]);
		}
		
		//��ȡ�� O(N)
		int res=N+1;
		int s=0, t=0, sum=0;
		while(true)
		{
			while(t<N && sum<S)
			{
				sum+=a[t++];
			}
			if(sum<S)
				break;
			res=min(res, t-s);
			sum-=a[s++];
		}
		
		if(res>N)
		{
			//�ⲻ���� 
			res=0;
		}
			
		printf("%d\n", res);
	}
	
	return 0;
}
