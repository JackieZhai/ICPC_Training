/*
加练题：codeforces-936A-Save Energy!
*/
#include <cstdio>
typedef long long ll;
int main()
{
    ll k,d,t,T;
    double ans= 0,st;
    scanf("%lld%lld%lld",&k,&d,&t);
    T=((k-1)/d+1)*d;//周期长度
    double T1 = k+(T-k)*0.5;//实际周期长度
    ll num = t/T1;//周期数
    ans=num*T;
    st = t - ll(t/T1)*T1;
    if(st<k)
        ans = ans+st;
    else
        ans = ans+k+(st-k)*2;
    printf("%.1lf",ans);
    return 0;
}