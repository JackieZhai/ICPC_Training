/*
例题：Expedition_POJ 2431 

目的是要求最小的加油次数；
所以，抽象模型为到燃料用尽在加油更加合理；
假想为：经过某加油站后，就获得了一次加油的“权利”(由于油箱是无穷大的)。 
*/
#include <cstdio> 
#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;

int L, P, N;
pair<int, int> F[10005];

bool cmp(pair<int, int> a,pair<int, int> b)
{
	return a.first<b.first;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d%d", &F[i].first, &F[i].second);
	scanf("%d%d", &L, &P);
	//为了写起来方便，把到终点的距离改为到起点的距离 
	for(int i=0; i<N; i++)
		F[i].first=L-F[i].first;
	
	//为了写起来方便，我们把终点也认为是加油站
	F[N].first=L;
	F[N].second=0;
	
	sort(F, F+N+1, cmp);
	
	priority_queue<int> que;
	
	int ans=0, pos=0, tank=P;
	//这里的输入是已经排好序的情况 
	for(int i=0; i<=N; i++)
	{
		int d=F[i].first-pos;
		while(tank-d<0)
		{
			if(que.empty())//没有路过加油站却没油了 
			{
				puts("-1");
				return 0;
			}
			tank+=que.top();//加最多油的加油站 
			que.pop();
			ans++;
		}
		tank-=d;
		pos=F[i].first;
		que.push(F[i].second);
	}
	printf("%d\n", ans);
	
	return 0;
}
