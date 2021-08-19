/*
��ϰ�⣺Chleaning Shifts_POJ 2376 

�����߶�ȫ�������⣺ 
̰��ģ�ͣ�������ѡȡ�ұ߽�ֵ�����Ǹ�����Ϊ���ǵĸ��졣 
*/
#include <cstdio> 
#include <iostream> 
#include <algorithm>
#include <ctime>
using namespace std;

pair<int, int> a[25005];
int minA=25001;
int N, T;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second>b.second;
}

void dfs(int x, int s)
{
	if(a[x].second==T)
	{
		if(minA>s)
			minA=s;
	}
	
	int e=a[x].second;
	for(int i=0; i<N; i++)
	{
		if(a[i].first<=a[x].first||a[i].first>=e+2)//ע��н��ԣ�ֻҪ�������С������������ּ��ɡ� 
			continue;
		else
		{
			dfs(i, s+1);
			break;//�ؼ�������Ѿ��ź����ˣ���һ��һ�������ģ�ֱ��break�� 
		}
	}
		
}


int main()
{

	scanf("%d%d", &N, &T);
	for(int i=0; i<N; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
//	clock_t start, end;
//	start=clock();	
	
	sort(a, a+N, cmp);
	
	for(int i=0; i<N; i++)
		if(a[i].first==1)
			dfs(i, 1);
	
	if(minA==25001)
		printf("-1\n");
	else	printf("%d\n",minA);
	
//	end=clock();
//	cout<<endl<<end-start<<"/"<<CLOCKS_PER_SEC<<"s"<<endl;
	return 0;
}
