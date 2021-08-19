#include<bits/stdc++.h>

using namespace std;
#define INF -99999999999

long long a[100010];
int main()
{

    long long i,n,maxn=0,minn=INF;

    scanf("%lld",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]>0)
            maxn+=a[i];

        if((abs)(a[i]%2)==1 && (abs)(a[i])<(abs)(minn))
            minn=a[i];
    }
    if((abs)(maxn%2)==1)
        printf("%lld",maxn);
    else if(minn>0 && maxn>0)
        printf("%lld",maxn-minn);
    else if(minn<0 && maxn>0)
        printf("%lld",maxn+minn);
    else
        printf("%lld",maxn+minn);



    return 0;
}
