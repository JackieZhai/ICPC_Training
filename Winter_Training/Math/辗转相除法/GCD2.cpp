/*
练习题：GCD & LCM Inverse_POJ 2429

	设答案为ans1,ans2， 
	ans1=a1*gcd，ans2=a2*gcd，a1,a2互质， 
	gcd*a1*b1=lcm，gcd*a2*b2=lcm， 
	a1*b1=lcm=(ans1*ans2)/gcd=a1*a2， 
	综上所诉，a1=b2,a2=b1。
	也就是说，ans1=gcd*k1，ans2=gcd*k2
	要求k1,k2尽量接近，并且k1,k2互质，并且，k2*k2=lcm/gcd
	需要用到Pollard_rho分解质因数，然后暴力搜索(dfs)寻找k1,k2。用了kuangbin大神的Pollard_rho模板。
	注意：输入的gcd和lcm一样的话，直接输出gcd,lcm即可。
*/ 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
const int S=20;

ll mult_mod(ll a,ll b,ll c)
{
    a%=c;
    b%=c;
    ll ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}

ll pow_mod(ll x,ll n,ll mod)
{
    if(n==1)return x%mod;
    x%=mod;
    ll tmp=x;
    ll ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}

bool check(ll a,ll n,ll x,ll t)
{
    ll ret=pow_mod(a,x,n);
    ll last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}

//Rabin-Miller强伪素数测试算法 
bool Miller_Rabin(ll n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;
    ll x=n-1;
    ll t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++)
    {
        ll a=rand()%(n-1)+1;
        if(check(a,n,x,t))
            return false;
    }
    return true;
}

ll factor[100];
int tol;

ll gcd(ll a,ll b)
{
    if(a==0)return 1;
    if(a<0) return gcd(-a,b);
    while(b)
    {
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}

//Pollard rho大数因数分解算法 
ll Pollard_rho(ll x,ll c)
{
    ll i=1,k=2;
    ll x0=rand()%x;
    ll y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        ll d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}

void findfac(ll n)
{
    if(Miller_Rabin(n))
    {
        factor[tol++]=n;
        return;
    }
    ll p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}

ll r[100];
int num;
ll k;

void dfs(ll now,int x,ll n)
{
    if(now>sqrt(n))
		return;
    k=max(k,now);
    for(int i=x;i<=num;i++)
		dfs(now*r[i],i+1,n);
}

int main()
{
    ll gcd,lcm,n;
    while(scanf("%lld%lld",&gcd,&lcm)!=EOF)
    {
        if(gcd==lcm)
        {
            printf("%lld %lld\n",gcd,lcm);
            continue;
        }
        tol=0;
        n=lcm/gcd;
        findfac(n); sort(factor,factor+tol);
        num=0; for(int i=0;i<=50;i++) r[i]=1;
        r[num]=factor[0];
        for(int i=1;i<tol;i++)
        {
            if(factor[i]==factor[i-1]) r[num]=r[num]*factor[i];
            else
            {
                num++;
                r[num]=factor[i];
            }
        }
        k=1; dfs(1,0,n);
        printf("%lld %lld\n",gcd*k,gcd*(n/k));
    }
    return 0;
}
