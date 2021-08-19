#include <bits/stdc++.h>
using namespace std;

const double eps=1e-7;

int n, k;
double l, v1, v2;
double d, t;

int main()
{
    scanf("%d%lf%lf%lf%d", &n, &l, &v1, &v2, &k);

    int kase=n/k;
    if(n%k!=0)
        kase++;
    if(kase-1==0)
    {
        printf("%.10lf\n", l/v2);
        return 0;
    }

    double busl=l*(v1+v2)/(2*v1*(kase-1)+v1+v2);
    double walkl=l-busl;
    double ans=(double)(kase-1)*(busl-walkl/(kase-1))+busl*kase;
    ans/=v2;

    printf("%.10lf\n", ans);



    return 0;
}
