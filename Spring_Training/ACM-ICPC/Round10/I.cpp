#include <cstdio>
using namespace std;

int N, T;

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        int ans=0;
        while(N!=0)
        {
            ans+=N/5;
            N/=5;
        }

        printf("%d\n", ans);
    }



    return 0;
}
