/*
练习题：Matrix_POJ 3685
	查找第M大的数 
	注意表达式是对i递增的，所以对于每个j在不同的i用二分 
*/
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N, M; 

//在搜索的过程中计算，因为存不下 
ll fun(const ll &i, const ll &j)
{
	return i*i+1e5*i+j*j-1e5*j+j*i;
}

bool C(const ll &mid)
{
	ll coun=0; //比mid小的数的个数
	for(int j=1; j<N+1; j++)
	{
		int lb=0, ub=N+1;
		while(ub-lb>1)
		{
			int i=(ub+lb)/2;
			if(fun(i, j)<mid)
				lb=i;
			else
				ub=i;
		}
		coun+=lb;
	}
	
	return coun<M;
}


int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%lld", &N, &M);
		
		ll lb=-1e5*N, ub=N*N+1e5*N+N*N+N*N;
		while(ub-lb>1)
		{
			ll mid=(ub+lb)/2;
			if(C(mid))
				lb=mid;
			else
				ub=mid;
		}
		
		printf("%lld\n", lb);
	}
	
	return 0;
}
