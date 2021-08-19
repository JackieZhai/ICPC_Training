/*
���⣺K-th Number_POJ 2104
	�߶���ʵ��---ռ�ÿռ��ʱ����һЩ 
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

int nums[MAX_N]; //��A����֮��Ľ�� 
vector<int> dat[ST_SIZE]; //�߶��������� 

//�����߶���
//k�ǽ��ı�ţ�������[l,r)��Ӧ
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
		
		//����STL��merge�������������ӵ����кϲ� 
		merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
	}
}

//����[i,j)�в�����x�����ĸ���
//k�ǽ��ı�ţ�������[l,r)��Ӧ
int query(int i, int j, int x, int k, int l, int r)
{
	if(j<=l || r<=i)
	{
		//��ȫ���ཻ 
		return 0;
	}
	else if(i<=l && r<=j)
	{
		//��ȫ���������� 
		return upper_bound(dat[k].begin(), dat[k].end(), x)-dat[k].begin();
	}
	else
	{
		//�Զ��ӵݹ�ļ���
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
		//��Ϊʵ���±�
		I[i]--, J[i]--;
	}
	
	
	
	for(int i=0; i<N; i++)
		nums[i]=A[i];
	sort(nums, nums+N);

	init(0, 0, N);
	
	for(int i=0; i<M; i++)
	{
		//����[l,r)�е�k����
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


