/*
例题：Layout_POJ 3169 
	此题属于线性规划问题，可以使用单纯形法进行求解。
	这道题中的不等式的特点就是所有的式子两边只出现了一个变量，属于差分约束系统；
	可以把其转化为有向图(带负边)用Bellman-Ford算法求解。 
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N=1007, MAX_ML=10007, MAX_MD=10007, INF=0x3f3f3f3f;

int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];

int d[MAX_N];

void solve()
{
	fill(d, d+N, INF);
	d[0]=0;
	
	//Bellman-Ford, 双重遍历更新d[]数组N次 
	for(int k=0; k<N; k++)
	{
		for(int i=0; i+1<N; i++)
		{
			if(d[i+1]<INF)
				d[i]=min(d[i], d[i+1]);//权值为0 
		}
		
		for(int i=0; i<ML; i++)
		{
			if(d[AL[i]-1]<INF)
				d[BL[i]-1]=min(d[AL[i]-1]+DL[i], d[BL[i]-1]);//权值为DL[i]
		}
		
		for(int i=0; i<MD; i++)
		{
			if(d[BD[i]-1]<INF)
				d[AD[i]-1]=min(d[AD[i]-1], d[BD[i]-1]-DD[i]);//权值为-DD[i]
		}
	}
	
	int res=d[N-1];
	if(d[0]<0)
	{
		res=-1;
	}
	else if(res==INF)
	{
		res=-2;
	}
	printf("%d\n", res);
}


int main()
{
	scanf("%d%d%d", &N, &ML, &MD);
	for(int i=0; i<ML; i++)
	{
		scanf("%d%d%d", &AL[i], &BL[i], &DL[i]);
	}
	for(int i=0; i<MD; i++)
	{
		scanf("%d%d%d", &AD[i], &BD[i], &DD[i]);
	}
	
	solve();
	
	return 0;
}
