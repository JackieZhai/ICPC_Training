/*
例题：A Simple Problem with Integers_POJ 3468
	树状数组实现
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


typedef long long ll;
const int MAX_N=100007, MAX_Q=100007;

int N, Q;
int A[MAX_N+1];
char T[MAX_Q];
int L[MAX_Q], R[MAX_Q], X[MAX_Q];

//树状数组
ll bit0[MAX_N+1], bit1[MAX_N+1];

ll sum(ll *b, int i)
{
	ll s=0;
	while(i>0)
	{
		s+=b[i];
		i-=i&-i;
	}
	return s;
}

void add(ll *b, int i, int v)
{
	while(i<=N)
	{
		b[i]+=v;
		i+=i&-i;
	}
}


int main()
{
	scanf("%d%d", &N, &Q);
	for(int i=1; i<=N; i++)
	{
		scanf("%d", &A[i]);
		add(bit0, i, A[i]);
	}
	for(int i=0; i<Q; i++)
	{
		getchar();
		scanf("%c", &T[i]);
		if(T[i]=='C')
		{
			scanf("%d%d%d", &L[i], &R[i], &X[i]);
			add(bit0, L[i], -X[i]*(L[i]-1));
			add(bit1, L[i], X[i]);
			add(bit0, R[i]+1, X[i]*R[i]);
			add(bit1, R[i]+1, -X[i]);
		}
		else
		{
			scanf("%d%d", &L[i], &R[i]);
			ll res=0;
			res+=sum(bit0, R[i])+sum(bit1, R[i])*R[i];
			res-=sum(bit0, L[i]-1)+sum(bit1, L[i]-1)*(L[i]-1);
			printf("%I64d\n", res);
		}
	}


	return 0;
}
