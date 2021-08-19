/*
练习题：Yogurt factory_POJ 2393

此题的问题主要是有内存的限制，不能开太大的数组;
其实也不必开cost[10005]，由于每一步输入的结果都是可以及时算出来的(对之后没有直接影响)，
所以只需要开一个cost就可以满足对之后的记录(用叠加S的概念)。 
这种没有“直接”影响就是贪心省时、省容量的本质。 
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
