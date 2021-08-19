/*
	d[i][0]表示[1,i]s1=s2(字典序)的方案数；d[i][1]表示s1>s2的方案数。最后答案就是d[n][1]/总方案数。
*/
#include<bits/stdc++.h> 
using namespace std;

const int MAX=1e5+7;
const int MOD=1e9+7;
typedef long long ll;

int a[MAX],b[MAX];
ll d[MAX][2];

//快速幂运算 
ll POW(ll x, ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1)
			res=res*x%MOD;
		x=x*x%MOD; 
		n>>=1;
	}
	return res;
}

int main()
{


    ll n,m;
	ll tot=0; //所有0的数目 
	 
    scanf("%I64d%I64d", &n, &m);
    for(int i=1; i<=n; i++)
		scanf("%d", &a[i]);
    for(int i=1; i<=n; i++)
		scanf("%d", &b[i]);
	
    memset(d,0,sizeof(d));
    d[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        tot+=(a[i]==0);
        tot+=(b[i]==0);
        if(a[i]&&b[i])
        {
            if(a[i]==b[i])
            {
                d[i][0]=d[i-1][0];
                d[i][1]=d[i-1][1];
            }
            else if(a[i]>b[i])
            {
                d[i][1]=(d[i-1][1]+d[i-1][0])%MOD;
                d[i][0]=0;
            }
            else
            {
                d[i][1]=d[i-1][1];
                d[i][0]=0;
            }
        }
        else if(a[i]==0&&b[i]==0)
        {
            d[i][0]=d[i-1][0]*m%MOD;
            d[i][1]=((d[i-1][1]*((m*m)%MOD)%MOD+d[i-1][0]*((m-1)*m/2)%MOD)%MOD)%MOD;
        }
        else if(a[i]==0)
        {
            d[i][0]=d[i-1][0]%MOD;
            d[i][1]=((d[i-1][0]*(m-b[i]))%MOD+(d[i-1][1]*m)%MOD)%MOD;
        }
        else if(b[i]==0)
        {
            d[i][0]=d[i-1][0]%MOD;
            d[i][1]=((d[i-1][0]*(a[i]-1))%MOD+(d[i-1][1]*m)%MOD)%MOD;
        }
    }
    
    //求乘法逆元：x^(MOD-2) % MOD (费马小定理)
    printf("%I64d\n", (d[n][1]*POW(POW(m,tot),MOD-2))%MOD);
    
    
    return 0;
}

