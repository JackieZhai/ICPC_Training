/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N=131072;
const ll EDGE=100000000000007LL;
const ll INF=0x3f3f3f3f;

ll a[MAX_N];
ll dat[MAX_N*2];
ll kit[57];
int n;
ll b;

ll mod_pow(ll x, ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n&1) res=res*x;
        x=x*x;
        n>>=1;
    }
    return res;
}

void update(int k, ll a)
{
    k+=n-1;
    dat[k]=a;
    while(k>0)
    {
        k=(k-1)/2;
        dat[k]=dat[k*2+1]+dat[k*2+2];
    }
}

void init()
{
    for(int i=0; i<n; i++)
        update(i, a[i]);
}

ll sum(int a, int b, int k, int l, int r)
{
    ll bufsum=0;

    if(r<=a || b<=l)
        return 0;
    if(a<=l && r<=b)
        return dat[k];
    else
    {
        bufsum+=sum(a, b, k*2+1, l, (l+r)/2);
        bufsum+=sum(a, b, k*2+2, (l+r)/2, r);
        return bufsum;
    }

}

int main()
{
    scanf("%d%I64d", &n, &b);
    for(int i=0; i<n; i++)
        scanf("%I64d", &a[i]);
    int n_=1;
    while(n_<n) n_*=2;
    for(int i=n; i<n_; i++)
        a[i]=INF;
    n=n_;

    init();

    int p=0;
    if(abs(b)==1)
    {
        kit[p++]=1;
        if(b==-1)
            kit[p++]=-1;
    }
    else
    {
        while(true)
        {
            ll buf=mod_pow(b, p);
            if(buf>EDGE)
                break;
            kit[p++]=buf;
        }
    }


    int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            for(int k=0; k<p; k++)
            {

                if(sum(i, j+1, 0, 0, n)==kit[k])
                {
                    ans++;
                    break;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn=100007;
typedef long long LL;
LL a[maxn],sum[maxn];
LL ans;
int n;

void solve(LL x)
{
	map<LL,int>mp;
	map<LL,int>::iterator it;
	for(int i=0; i<n; i++)
	{
		++mp[sum[i]];
		it = mp.find(sum[i+1]-x);
		if(it!=mp.end())//存在
			ans += it->second;
	}
}

int main()
{
	LL k;
	while(scanf("%d%I64d",&n,&k)!=EOF)
	{
		sum[0]=0;
		for(int i=1;i<=n;++i)
        {
			scanf("%I64d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		ans=0;
		if(k==1)
			solve(1);
		else if(k==-1)
		{
			solve(1);//对于子序列和为1的肯定也是-1的偶数次幂
			solve(-1);
		}
		else
		{
			LL cnt=1;
			while(cnt<=1e9*n)
			{
				solve(cnt);
				cnt*=k;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
