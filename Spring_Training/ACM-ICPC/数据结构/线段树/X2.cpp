/*
例题：A Simple Problem with Integers_POJ 3468
	线段树实现
*/
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;
const int DAT_SIZE=(1<<18)-1;
const int MAX_N=100007, MAX_Q=100007;

int N, Q;
int A[MAX_N];
char T[MAX_Q];
int L[MAX_Q], R[MAX_Q], X[MAX_Q];

//线段树
ll data[DAT_SIZE], datb[DAT_SIZE];

//对区间[a,b)同时加x
//k是节点的编号，对应区间[l,r)
void add(int a, int b, int x, int k, int l, int r)
{
	if(a<=l&&r<=b)
	{
		data[k]+=x;
	}
	else if(l<b&&a<r)
	{
		datb[k]+=(min(b, r)-max(a, l))*x;
		add(a, b, x, k*2+1, l, (l+r)/2);
		add(a, b, x, k*2+2, (l+r)/2, r);
	}
}

//计算[a,b)的和
//k是节点的编号，对应区间[l,r)
ll sum(int a, int b, int k, int l, int r)
{
	if(b<=l||r<=a)
	{
		return 0;
	}
	else if(a<=l&&r<=b)
	{
		return data[k]*(r-l)+datb[k];
	}
	else
	{
		ll res=(min(b,r)-max(a,l))*data[k];
		res+=sum(a, b, k*2+1, l, (l+r)/2);
		res+=sum(a, b, k*2+2, (l+r)/2, r);
		return res;
	}
}

int main()
{
	scanf("%d%d", &N, &Q);
	for(int i=0; i<N; i++)
	{
		scanf("%d", &A[i]);
		add(i, i+1, A[i], 0, 0, N);
	}
	for(int i=0; i<Q; i++)
	{
		getchar();
		scanf("%c", &T[i]);
		if(T[i]=='C')
		{
			scanf("%d%d%d", &L[i], &R[i], &X[i]);
			add(L[i]-1, R[i], X[i], 0, 0, N);
		}
		else
		{
			scanf("%d%d", &L[i], &R[i]);
			printf("%I64d\n", sum(L[i]-1, R[i], 0, 0, N));
		}
	}



	return 0;
}
