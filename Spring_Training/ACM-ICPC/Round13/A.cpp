#include <bits/stdc++.h>
using namespace std;

pair<int, int> p[107];
int n;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &p[i].first);
        p[i].second=i+1;
    }
    sort(p, p+n);

    for(int i=0; i<n/2; i++)
    {
        printf("%d %d\n", p[i].second, p[n-i-1].second);
    }




    return 0;
}
