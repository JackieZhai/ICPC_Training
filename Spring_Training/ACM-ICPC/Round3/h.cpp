#include <cstdio>
#include <algorithm>
using namespace std;

int a[1007];
int n;

int main()
{

    while(scanf("%d", &n)!=EOF)
    {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);

        sort(a, a+n);

        int ans=0;
        for(int i=0; i<n; i++)
        {
            int mul=a[i]*(n-i);
            if(ans<mul)
                ans=mul;
        }
        printf("%d\n", ans);


    }

    return 0;
}
