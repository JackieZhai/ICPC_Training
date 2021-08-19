#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[107];
int v, n;
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first>b.first;
}

int main()
{
    while(scanf("%d", &v)!=EOF)
    {
        if(v==0)
            break;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &a[i].first, &a[i].second);
        }
        sort(a, a+n, cmp);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(v>a[i].second)
            {
                v-=a[i].second;
                ans+=a[i].first*a[i].second;
            }
            else
            {
                ans+=a[i].first*v;
                break;
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}
