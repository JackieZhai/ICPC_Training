/*
��ϰ�⣺Smallest Difference_POJ 2718

�����õ���next_permutation()����٣��ؼ���������mid���÷���ʹ�ò��ò��Ϊ�������飻
���⣬���⻹������̰���㷨��⣺
1������������ż����ʱ��ȥ�м�������Ϊ������λ������λС�ĺ����������λ��ĺ�����С��
2������������������ʱ����λ�������С��λ���ٵ���� 
*/
#include <cstdio> 
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int a[10],T;
	scanf("%d", &T);
	getchar();
	while(T--)
	{
		int n=0;
		memset(a, 0, sizeof(a));
		string st;
		getline(cin, st);
		for(int i=0; i!=st.size(); i++)
			if(st[i]<='9'&&st[i]>='0')
			{
				a[n++]=st[i]-'0';
			}
		
		//���������Ѿ��ź��򣬲�����û����������sort()��һ�¼��� 
		if(n==2)
		{
			printf("%d\n", a[1]-a[0]);
			continue;
		}
		while(a[0]==0)
			next_permutation(a, a+n);
		int mid=(n+1)/2;
		int ans=999999999;
		do
		{
			if(a[mid]==0)
				continue;
			int c=0, b=0;
			for(int i=0; i<mid; i++)
				c=c*10+a[i];
			for(int i=mid; i<n; i++)
				b=b*10+a[i];
			if(ans>abs(c-b))
				ans=abs(c-b);
		}while(next_permutation(a, a+n));
		printf("%d\n", ans);
	}
	
	return 0;
}
