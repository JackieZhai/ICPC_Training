/*
��ϰ�⣺Yogurt factory_POJ 2393

�����������Ҫ�����ڴ�����ƣ����ܿ�̫�������;
��ʵҲ���ؿ�cost[10005]������ÿһ������Ľ�����ǿ��Լ�ʱ�������(��֮��û��ֱ��Ӱ��)��
����ֻ��Ҫ��һ��cost�Ϳ��������֮��ļ�¼(�õ���S�ĸ���)�� 
����û�С�ֱ�ӡ�Ӱ�����̰��ʡʱ��ʡ�����ı��ʡ� 
*/
#include <cstdio> 
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;


int N, S;
vector<int> cost;
long long ans=0;

int main()
{

	scanf("%d%d", &N, &S);
	for(int i=0; i<N; i++)
	{
		int buf1, buf2;
		scanf("%d%d", &buf1, &buf2);
		cost.push_back(buf1);
		for(int j=0; j<i; j++)
			cost[j]+=S;
	
	
		int minC=5001;
		for(int j=i; j>=0; j--)
			minC = min(minC, cost[j]);
		ans+=minC*buf2;
	}
	
	printf("%lld\n", ans);
	
	
	
	return 0;
}
