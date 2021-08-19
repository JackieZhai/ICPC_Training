/*
区间调度问题：
	对于每项工作有开始时间s和结束时间t，参与工作不可重叠(即使是开始与结束的瞬间也不行)
	输出最多可以参与的工作。
此题的贪心关键在于模型的建立：在可选的工作中，每次都选取结束时间最早的工作。 
*/
#include <cstdio> 
#include <iostream> 
#include <algorithm>
using namespace std; 

const int MAX_N=100000;
int N, S[MAX_N], T[MAX_N];
//排序时需要将工作打包，只排序结束时间 
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
	//sort()排序pair是默认排序.first
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
