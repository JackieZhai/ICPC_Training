/*
例题：K-th Number_POJ 2104
	平方分割实现---占用空间小，时间大一些（但是满足条件） 
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int B=1000; //桶的大小 
const int MAX_N=100000, MAX_M=5000;

int N, M;
int A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];

int nums[MAX_N]; //对A排序之后的结果 
vector<int> bucket[MAX_N/B]; //每个桶排序之后的结果 

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", &A[i]);
	for(int i=0; i<M; i++)
	{
		scanf("%d%d%d", &I[i], &J[i], &K[i]);
		//改为实际下标
		I[i]--, J[i]--;
	}

	
	for(int i=0; i<N; i++)
	{
		bucket[i/B].push_back(A[i]);
		nums[i]=A[i];
	}
	sort(nums, nums+N);
	//虽然B个一组剩下的部分所在的桶没有排序，但是不会产生问题
	for(int i=0; i<N/B; i++)
		sort(bucket[i].begin(), bucket[i].end());
	
	for(int i=0; i<M; i++)
	{
		//求[l,r)区间中第k个数
		int l=I[i], r=J[i]+1, k=K[i];
		
		int lb=-1, ub=N-1;
		while(ub-lb>1)
		{
			int md=(lb+ub)/2;
			int x=nums[md];
			int tl=l, tr=r, c=0;
			
			//区间两端多出的部分
			while(tl<tr && tl%B!=0)
				if(A[tl++]<=x)
					c++;
			while(tl<tr && tr%B!=0)
				if(A[--tr]<=x)
					c++;
			
			//对每一个桶进行计算
			while(tl<tr)
			{
				int b=tl/B;
				c+=upper_bound(bucket[b].begin(), bucket[b].end(), x)-bucket[b].begin();
				tl+=B;
			}
			 
			if(c>=k)
				ub=md;
			else
				lb=md;
		}
		
		printf("%d\n", nums[ub]);
	}
	
	
	

	return 0;
}
