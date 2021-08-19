/*
练习题：Yogurt factory_POJ 2393

此题的关键在于先选谁：贪心模型的建立。
cow的t/d越小应该先选，因为他们的运算是乘法关系，t越小越先选、d越大越急迫。 

而这题与T5刚好相反，TLE的限制更多，所以不止用sum每次都要累加一遍，
而是用sum[100005]把每次的和存起来，下一次加一个就行了。 
*/
#include <cstdio> 
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;


int N;
long long ans=0;
long long sum[100005];
pair<long long, long long> cow[100005];//.First是时间，.second是单位时间吃花数。 


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
