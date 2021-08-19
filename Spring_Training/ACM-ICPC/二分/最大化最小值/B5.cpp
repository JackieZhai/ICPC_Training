/*
练习题：Monthly Expense_POJ 3273 
	最小化最大和，关键是C()判断函数的改写 
*/
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N=1000007, INF=0x3f3f3f3f;

int N, M;
int x[MAX_N];

bool C(int s)
{
	int sum=0;
	int par=1;
	for(int i=0; i<N; i++)
	{
		sum+=x[i];
		if(sum>s)
		{
			sum=x[i];
			par++;
		}
	}
	
	if(par<=M)
		return true;
	else
		return false;
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", &x[i]);
	
	int lb=0;
	for(int i=0; i<N; i++)
	{
		if(lb<x[i])
			lb=x[i];
	}
	int ub=INF;
	
	while(ub-lb>=1) 
	{
		int mid=(lb+ub)/2;
		if(C(mid))
			ub=mid;
		else
			lb=mid+1; //注意最大化最小值的时候lb=mid+1 而且while(ub-lb>=1) 
	}
	
	printf("%d\n", ub);
	
	return 0;
}







/*此为错误做法，需要在每次minN求和时遍历所有元素，找和最小的才行 
priority_queue<int, vector<int>, greater<int> > que;
int N, M;

int main()
{
	while(scanf("%d%d", &N, &M)!=EOF)
	{
		for(int i=0; i<N; i++)
		{
			int buf;
			scanf("%d", &buf);
			que.push(buf);
		}
		
		while(que.size()!=M)
		{
			int minF=que.top();
			que.pop();
			int minS=que.top();
			que.pop();
			int minN=minF+minS;
			que.push(minN);
		}
		
		for(int i=0; i<M-1;  i++)
			que.pop();
		printf("%d\n", que.top());
		que.pop();
	}
	
	return 0;
}
*/ 
