#include <bits/stdc++.h>
using namespace std;



int a[57][2];
int n, x;

int main()
{
    scanf("%d%d", &n, &x);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d", &a[i][0], &a[i][1]);
    }

    int ans=0;
    ans+=(a[0][0]-1)%x;
    for(int i=0; i<n-1; i++)
    {
        ans+=(a[i+1][0]-a[i][1]-1)%x;
    }
    for(int i=0; i<n; i++)
    {
        ans+=(a[i][1]-a[i][0]+1);
    }
    printf("%d\n", ans);




    return 0;
}
