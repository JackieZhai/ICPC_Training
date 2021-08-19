/*
��ϰ�⣺Allowance_POJ 3040
	����̰�� 
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
	bool flag = true;		//�Ƿ��ܼ����� 
	for (int i = 0 ; i < n ; i++)
	{
		if (coin[i].v >= c)
			ans += coin[i].m;
		else		//���ȴӴ���С�� 
		{
			while (coin[i].m)
			{
				int t = 0;		//�Ѿ��õ�Ǯ�� 
				for (int j = i ; j < n ; j++)
				{
					if (!coin[j].m)		//ûǮ�˾����� 
						continue;
					while (coin[j].m && t < c)
					{
						t += coin[j].v;
						coin[j].m--;
					}
					if (t == c)		//������÷���ͷ��� 
					{
						ans++;
						break;
					}
					else		//������������� 
					{
						t -= coin[j].v;
						coin[j].m++;
					}
				}
				if (t == c)
					continue;
				for (int j = n - 1 ; j >= i ; j--)		//�����ٴ�С������ 
				{
					if (!coin[j].m)
						continue;
					if (t + coin[j].m * coin[j].v >= c)		//���þ���
					{
						ans++;
						coin[j].m -= (c - t + coin[j].v - 1) / coin[j].v;
						t = c;		//���������Ƕ���Ǯ���Ͱ�c�� 
						break;
					}
					else		//������������ 
					{
						t += coin[j].m * coin[j].v;
						coin[j].m = 0;
					}
				}
				if (t < c)		//����������ã����޷��ٷ�����
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
