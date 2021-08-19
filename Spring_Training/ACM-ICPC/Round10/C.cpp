#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m, w;

int main()
{
    scanf("%I64d%I64d", &w, &m);

    while(m!=0)
    {
        ll l=m-1;
        ll r=m+1;

        if(l%w==0)
        {
            m--;
            m/=w;
        }
        else if(r%w==0)
        {
            m++;
            m/=w;
        }
        else if(m%w==0)
        {
            m/=w;
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");


    return 0;
}
