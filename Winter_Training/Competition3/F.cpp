/*
	�������������TLE�������¼�����MLE��
	ֻ����������ѷ����֪��n>4ʱ��������������Ϊn-1��������ǽ��Ϊ0�� 
	���⣬����ɸ��Ҳ��MLE�� 
*/ 
#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
	for(int i=2; i*i<=n; i++)
	{
		if(n%i==0)
			return false;
	}
	return n!=1; //1������ 
}

int main()
{	
	int T;
	scanf("%d", &T);

	
	while(T--)
	{
		int n;
		scanf("%d", &n);
		if(n==1)
			printf("0\n");
		else if(n==2)
			printf("1\n");
		else if(n==3||n==4)
			printf("2\n");
		else
		{
			if(is_prime(n))
				printf("%d\n", n-1);
			else
				printf("0\n");			
		}
	}
	
	
	
	return 0;
}
