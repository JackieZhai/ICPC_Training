/*
练习题：Allowance_POJ 3040
	经典贪心 
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
struct node
{
	ll v,m;
}coin[27];
bool cmp(node a,node b)
{
	return a.v > b.v;
}


int main()
{
	ll n,c;
	ll ans;
	scanf ("%lld %lld",&n,&c);
	for (int i = 0 ; i < n ; i++)
		scanf("%lld %lld",&coin[i].v,&coin[i].m);
	
	sort (coin , coin + n , cmp);
	
	ans = 0;
	bool flag = true;		//是否能继续拿 
	for (int i = 0 ; i < n ; i++)
	{
		if (coin[i].v >= c)
			ans += coin[i].m;
		else		//首先从大往小拿 
		{
			while (coin[i].m)
			{
				int t = 0;		//已经拿的钱数 
				for (int j = i ; j < n ; j++)
				{
					if (!coin[j].m)		//没钱了就跳过 
						continue;
					while (coin[j].m && t < c)
					{
						t += coin[j].v;
						coin[j].m--;
					}
					if (t == c)		//如果正好发完就发了 
					{
						ans++;
						break;
					}
					else		//否则就再往下搜 
					{
						t -= coin[j].v;
						coin[j].m++;
					}
				}
				if (t == c)
					continue;
				for (int j = n - 1 ; j >= i ; j--)		//不够再从小往大拿 
				{
					if (!coin[j].m)
						continue;
					if (t + coin[j].m * coin[j].v >= c)		//够拿就拿
					{
						ans++;
						coin[j].m -= (c - t + coin[j].v - 1) / coin[j].v;
						t = c;		//管它后来是多少钱，就按c算 
						break;
					}
					else		//不够就先拿完 
					{
						t += coin[j].m * coin[j].v;
						coin[j].m = 0;
					}
				}
				if (t < c)		//如果还不够拿，则无法再发工资
				{
					flag = false; 
					break;
				}
			}
		}
		if (!flag)
			break;
	}
	printf ("%lld\n",ans);

	return 0;
} 
