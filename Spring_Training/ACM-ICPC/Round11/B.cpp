#include <bits/stdc++.h>
using namespace std;


int n, v;
int coun[3007];
int add[3007];


int main()
{
    scanf("%d%d", &n, &v);
    for(int i=0; i<n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        coun[a]+=b; //ע�⣡
    }

    int ans=0;
    for(int i=0; i<3005; i++)
    {
        int vi=v;
        if(add[i]!=0)
        {
            if(add[i]<=vi)
            {
                ans+=add[i];
                vi-=add[i];
            }
            else
            {
                ans+=vi;
                vi=0;
            }
        }
        if(coun[i]!=0)
        {
            //cout<<i<<"-"<<ans<<endl;
            if(coun[i]<=vi)
            {
                ans+=coun[i];
            }
            else
            {
                ans+=vi;
                coun[i]-=vi;
                add[i+1]+=coun[i];
            }
        }
    }

    printf("%d\n", ans);



    return 0;
}
