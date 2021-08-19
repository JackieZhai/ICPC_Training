#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn=100007;
int n;
struct Node{
    ll r, e, l;
    friend bool operator < (const Node& a, const Node& b)
    {
        return a.e<b.e;
    }
} num[maxn];


int main()
{
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++)
    {
        printf("Case #%d: ", kase);
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%lld%lld%lld", &num[i].r, &num[i].e, &num[i].l);
        }
        sort(num, num+n);

        ll store=num[0].e;

        bool flag=true;
        for(int i=0; i<n-1; i++)
        {
            if(store<num[i].r)
            {
                flag=false;
                printf("NO\n");
                break;
            }
            store+=num[i+1].e-num[i].e-num[i].l;
        }
        if(flag && store<num[n-1].r)
        {
            flag=false;
            printf("NO\n");
        }
        if(flag)
        {
            printf("YES\n");

        }






    }




    return 0;
}
