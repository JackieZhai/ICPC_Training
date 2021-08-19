/*
例题：K-th Number_POJ 2104
	线段树实现---占用空间大，时间少一些 
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ST_SIZE=(1<<18)-1;
const int MAX_N=100000, MAX_M=5000;

int N, M;
int A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];

int nums[MAX_N]; //对A排序之后的结果 
vector<int> dat[ST_SIZE]; //线段树的数据 

//构建线段树
//k是结点的编号，和区间[l,r)对应
void init(int k, int l, int r)
{
	if(r-l==1)
	{
		dat[k].push_back(A[l]);
	}
	else
	{
		int lch=k*2+1, rch=k*2+2;
		init(lch, l, (l+r)/2);
		init(rch, (l+r)/2, r);
		dat[k].resize(r-l);
		
		//利用STL的merge函数吧两个儿子的数列合并 
		merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
	}
}

//计算[i,j)中不超过x的数的个数
//k是结点的编号，和区间[l,r)对应
int query(int i, int j, int x, int k, int l, int r)
{
	if(j<=l || r<=i)
	{
		//完全不相交 
		return 0;
	}
	else if(i<=l && r<=j)
	{
		//完全包含在里面 
		return upper_bound(dat[k].begin(), dat[k].end(), x)-dat[k].begin();
	}
	else
	{
		//对儿子递归的计算
		int lc=query(i, j, x, k*2+1, l, (l+r)/2);
		int rc=query(i, j, x, k*2+2, (l+r)/2, r);
		return lc+rc; 
	}
}

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
		nums[i]=A[i];
	sort(nums, nums+N);

	init(0, 0, N);
	
	for(int i=0; i<M; i++)
	{
		//查找[l,r)中第k个数
		int l=I[i], r=J[i]+1, k=K[i];
		
		int lb=-1, ub=N-1;
		while(ub-lb>1)
		{
			int md=(ub+lb)/2;
			int c=query(l, r, nums[md], 0, 0, N);
			
			if(c>=k)
				ub=md;
			else
				lb=md;
		}
		
		printf("%d\n", nums[ub]);
	}
	
	
	return 0;
}


