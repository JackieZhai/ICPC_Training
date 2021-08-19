#include <bits/stdc++.h>
using namespace std;

char a[20];

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	int n=0;
	long long int b, max=0;
	scanf("%s",a);
	for(int i=0; a[i]!='\0'; i++)
	{	
		n++;
	}
	
	scanf("%I64d",&b);
	sort(a, a+n, cmp);
	do{
		int count=0;
		if(a[0]=='0')
			continue;
		long long int sum=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<(a[n-i-1]-'0'); j++)
				sum+=pow(10, i);
		if(max<sum&&sum<=b)
			max=sum;
	}while(prev_permutation(a, a+n));
	
	printf("%I64d\n", max);
	
	return 0;
}
