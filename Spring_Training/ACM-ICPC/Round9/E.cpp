#include <bits/stdc++.h>
using namespace std;





int main()
{
    long long ans=0;
    long long ans2;
    for(int i=1; ans<1000000000; i++)
    {
        ans2=ans;
        int p=i;
        while(p!=0)
        {
            ans2+=p%10;
            p/=10;
        }
        if(ans2-ans>70)
            printf("%lld\n", ans2-ans);
    }





    return 0;
}
