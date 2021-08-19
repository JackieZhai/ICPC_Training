/*
此为贪心练习题：Stall Reservations_POJ 3190
	TLE原因：需要在起点升序基础上用终点升序的优先队列进行维护，才可750MS左右完成。 
	详见：http://blog.csdn.net/chang_mu/article/details/40982387 
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
using namespace std;


struct node{
	int x,y,in; 
	friend bool operator<(const node& a, const node& b) {  
        return a.y > b.y;  
    }  
}a[50005];

int N;
map<int, int> stall;
bool mark[50005];
int k=0;

bool cmp(node a, node b)
{
	return a.x<b.x;
}




int main()
{

	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].in=i;
	}
	
	memset(mark, false, sizeof(mark));
	
	sort(a, a+N, cmp);
	
	int k=1;
	node tmp;
	priority_queue<node> pq;
	pq.push(a[0]);
	stall[a[0].in]=k;
	
	for(int i=1; i<N; i++)
	{
		tmp=pq.top();
		if(a[i].x>tmp.y)
		{
			tmp.y=a[i].y;
			stall[a[i].in]=stall[tmp.in];
			pq.pop();
			pq.push(tmp);
		}
		else
		{
			stall[a[i].in] = ++k;
			pq.push(a[i]);
		}
	}
	
	printf("%d\n", k);
	for(int i=0; i<N; i++)
	{
		printf("%d\n", stall[i]);
	}
	
	

	return 0;
}
