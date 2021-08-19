/*
例题：Jessica's Reading Problem_POJ 3320
	
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
	int n=all.size(); //全部知识点的总数
	
	// 尺取法 
	int s=0, t=0, num=0;
	map<int, int> coun; //统计知识点出现的次数 
	int res=P;
	while(true)
	{
		while(t<P && num<n)
		{
			if(coun[a[t++]]++ == 0)
			{
				//出现新的知识点 
				num++;
			}
		}
		if(num<n)
			break;
		res=min(res, t-s);
		if(--coun[a[s++]] == 0)
		{
			//某个知识点出现次数为零了
			num--; 
		}
	}
	
	printf("%d\n", res);
	
	
	
	
	return 0;
}
