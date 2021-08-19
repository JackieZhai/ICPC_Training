#include <bits/stdc++.h>
using namespace std;



int n, k;
int times;



int main()
{
    scanf("%d%d", &n, &k);
    times=n/2;

    if(n<2)
    {
        if(k==0)
            printf("1\n");
        else
            printf("-1\n");
    }
    else if(k<times)
    {
        printf("-1\n");
    }
    else
    {
        int first=k-(times-1);
        int second=first*2+1;
        printf("%d %d", first, first*2);
        for(int i=0; i<n-2; i++)
        {
            printf(" %d", second+i);
        }
        printf("\n");
    }





    return 0;
}
