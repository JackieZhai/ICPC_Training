/**
维护O(logn)的线段树：
    1. Q: 查询区间的和
    2. C: 对区间增加值
*/
#include <cstdio>
using namespace std;

typedef long long ll;
const int Maxn = 100007;
ll a[Maxn << 2], lazy[Maxn << 2], n, Q, l, r, p;
char str[10];

void pushUp(ll rt)
{
	a[rt] = a[rt << 1] + a[rt << 1 | 1];
}

void pushDown(ll rt, ll m)
{
	if(lazy[rt])
    {
		lazy[rt << 1] += lazy[rt];
		lazy[rt << 1 | 1] += lazy[rt];
		a[rt << 1] += (m - (m >> 1)) * lazy[rt];
		a[rt << 1 | 1] += (m >> 1) * lazy[rt];
		lazy[rt] = 0;
	}
}

void bulid(ll l, ll r, ll rt)
{
	if(l == r)
    {
		scanf("%lld", &a[rt]);
		return ;

	}
	ll mid = (l + r) >> 1;
	bulid(l, mid, rt << 1);
	bulid(mid + 1, r, rt << 1 | 1);
	pushUp(rt);
}

ll query(ll L, ll R, ll l, ll r, ll rt)
{
	if(L <= l && r <= R)
		return a[rt];
	pushDown(rt, r - l + 1);
	ll mid = (l + r) >> 1, ret = 0;
	if(L <= mid)
		ret += query(L, R, l, mid, rt << 1);
	if(mid < R)
		ret += query(L, R, mid + 1, r, rt << 1 | 1);
	return ret;
}

void update(ll L, ll R, ll addv, ll l, ll r, ll rt)
{
	if(L <= l && r <= R)
    {
		lazy[rt] += addv;
		a[rt] += addv * (r - l + 1);
		return ;
	}
	pushDown(rt, r - l + 1);
	ll mid = (l + r) >> 1;
	if(L <= mid)
		update(L, R, addv, l, mid, rt << 1);
	if(mid < R)
		update(L, R, addv, mid + 1, r, rt << 1 | 1);
	pushUp(rt);
}

int main()
{
	scanf("%lld%lld", &n, &Q);

	bulid(1, n, 1);

	while(Q--)
    {
        getchar();
		scanf("%s%lld%lld", str, &l, &r);
		if(str[0] == 'Q')
		{
			printf("%lld\n", query(l, r, 1, n, 1));
		}
		else
		{
			scanf("%lld", &p);
			update(l, r, p, 1, n, 1);
		}
	}

	return 0;
}
