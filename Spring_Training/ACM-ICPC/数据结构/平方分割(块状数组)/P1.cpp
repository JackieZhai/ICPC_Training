/*
���⣺K-th Number_POJ 2104
	ƽ���ָ�ʵ��---ռ�ÿռ�С��ʱ���һЩ���������������� 
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int B=1000; //Ͱ�Ĵ�С 
const int MAX_N=100000, MAX_M=5000;

int N, M;
int A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];

int nums[MAX_N]; //��A����֮��Ľ�� 
vector<int> bucket[MAX_N/B]; //ÿ��Ͱ����֮��Ľ�� 

int main()
{
	scanf("%d%d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", &A[i]);
	for(int i=0; i<M; i++)
	{
		scanf("%d%d%d", &I[i], &J[i], &K[i]);
		//��Ϊʵ���±�
		I[i]--, J[i]--;
	}

	
	for(int i=0; i<N; i++)
	{
		bucket[i/B].push_back(A[i]);
		nums[i]=A[i];
	}
	sort(nums, nums+N);
	//��ȻB��һ��ʣ�µĲ������ڵ�Ͱû�����򣬵��ǲ����������
	for(int i=0; i<N/B; i++)
		sort(bucket[i].begin(), bucket[i].end());
	
	for(int i=0; i<M; i++)
	{
		//��[l,r)�����е�k����
		int l=I[i], r=J[i]+1, k=K[i];
		
		int lb=-1, ub=N-1;
		while(ub-lb>1)
		{
			int md=(lb+ub)/2;
			int x=nums[md];
			int tl=l, tr=r, c=0;
			
			//�������˶���Ĳ���
			while(tl<tr && tl%B!=0)
				if(A[tl++]<=x)
					c++;
			while(tl<tr && tr%B!=0)
				if(A[--tr]<=x)
					c++;
			
			//��ÿһ��Ͱ���м���
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
