/*
���⣺Jessica's Reading Problem_POJ 3320
	
*/
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int MAX_P=1000007;

int P;
int a[MAX_P]; 

int main()
{
	scanf("%d", &P);
	for(int i=0; i<P; i++)
		scanf("%d", &a[i]);
	
	set<int> all;
	for(int i=0; i<P; i++)
		all.insert(a[i]);
	int n=all.size(); //ȫ��֪ʶ�������
	
	// ��ȡ�� 
	int s=0, t=0, num=0;
	map<int, int> coun; //ͳ��֪ʶ����ֵĴ��� 
	int res=P;
	while(true)
	{
		while(t<P && num<n)
		{
			if(coun[a[t++]]++ == 0)
			{
				//�����µ�֪ʶ�� 
				num++;
			}
		}
		if(num<n)
			break;
		res=min(res, t-s);
		if(--coun[a[s++]] == 0)
		{
			//ĳ��֪ʶ����ִ���Ϊ����
			num--; 
		}
	}
	
	printf("%d\n", res);
	
	
	
	
	return 0;
}
