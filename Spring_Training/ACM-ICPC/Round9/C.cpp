#include <bits/stdc++.h>
using namespace std;

int n;


int main()
{
    scanf("%d", &n);
    if(n<=3)
        printf("NO\n");
    else
    {
        printf("YES\n");
        if(n%2==0)
        {
            printf("1 * 2 = 2\n");
            printf("2 * 3 = 6\n");
            printf("6 * 4 = 24\n");
            for(int i=5; i<=n-1; i+=2)
            {
                printf("%d - %d = 1\n", i+1, i);
            }
            for(int i=5; i<=n-1; i+=2)
            {
                printf("24 * 1 = 24\n");
            }
        }
        else
        {
            printf("2 * 4 = 8\n");
            printf("3 * 5 = 15\n");
            printf("1 + 8 = 9\n");
            printf("9 + 15 = 24\n");
            for(int i=6; i<=n-1; i+=2)
            {
                printf("%d - %d = 1\n", i+1, i);
            }
            for(int i=6; i<=n-1; i+=2)
            {
                printf("24 * 1 = 24\n");
            }
        }
    }


    return 0;
}
