/*
����������⣺
	����ÿ����п�ʼʱ��s�ͽ���ʱ��t�����빤�������ص�(��ʹ�ǿ�ʼ�������˲��Ҳ����)
	��������Բ���Ĺ�����
�����̰�Ĺؼ�����ģ�͵Ľ������ڿ�ѡ�Ĺ����У�ÿ�ζ�ѡȡ����ʱ������Ĺ����� 
*/
#include <cstdio> 
#include <iostream> 
#include <algorithm>
using namespace std; 

const int MAX_N=100000;
int N, S[MAX_N], T[MAX_N];
//����ʱ��Ҫ�����������ֻ�������ʱ�� 
pair<int, int> itv[MAX_N];


int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &S[i]);
	for(int i=0; i<N; i++)
		scanf("%d", &T[i]);
	
	for(int i=0; i<N; i++)
	{
		itv[i].first=T[i];
		itv[i].second=S[i];
	}
	//sort()����pair��Ĭ������.first
	sort(itv, itv+N);
	
	int ans=0, t=0;
	for(int i=0; i<N; i++)
	{
		if(t<itv[i].second)
		{
			ans++;
			t=itv[i].first;
		}
	 } 
	printf("%d", ans);
	
	
		
	return 0;
} 
