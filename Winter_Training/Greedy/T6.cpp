/*
��ϰ�⣺Yogurt factory_POJ 2393

����Ĺؼ�������ѡ˭��̰��ģ�͵Ľ�����
cow��t/dԽСӦ����ѡ����Ϊ���ǵ������ǳ˷���ϵ��tԽСԽ��ѡ��dԽ��Խ���ȡ� 

��������T5�պ��෴��TLE�����Ƹ��࣬���Բ�ֹ��sumÿ�ζ�Ҫ�ۼ�һ�飬
������sum[100005]��ÿ�εĺʹ���������һ�μ�һ�������ˡ� 
*/
#include <cstdio> 
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;


int N;
long long ans=0;
long long sum[100005];
pair<long long, long long> cow[100005];//.First��ʱ�䣬.second�ǵ�λʱ��Ի����� 


bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
	return (a.first*1.0/a.second<b.first*1.0/b.second);
}

int main()
{

	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		scanf("%d%d", &cow[i].first, &cow[i].second);
	}
	
	sort(cow, cow+N, cmp);
	
	for(int i=N-2; i>=0; i--)
	{
		sum[i]=sum[i+1]+cow[i+1].second;
		ans+=2*cow[i].first*sum[i];
	}
	
	
	
	printf("%lld\n", ans);
	
	
	
	return 0;
}
