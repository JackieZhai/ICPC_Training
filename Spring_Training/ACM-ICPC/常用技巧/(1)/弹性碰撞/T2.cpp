/**
例题：Ants_POJ 1852

*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX_N=1000007;

int L, n;
int x[MAX_N];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &L, &n);
        for(int i=0; i<n;  i++)
            scanf("%d", &x[i]);


        int minT=0;
        for(int i=0; i<n; i++)
        {
            minT=max(minT, min(x[i], L-x[i]));
        }

        //计算最长时间
        int maxT=0;
        for(int i=0; i<n; i++)
        {
            maxT=max(maxT, max(x[i], L-x[i]));
        }

        printf("%d %d\n", minT, maxT);
    }


    return 0;
}
