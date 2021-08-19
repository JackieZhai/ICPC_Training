#include <bits/stdc++.h>
using namespace std;


int n;
int b[100007];
int b1[50007];
int b2[50007];

int main()
{
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++)
    {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &b[i]);
        }

        for(int i=0; i<n; i++)
            if(i%2==0)
                b1[i/2]=b[i];
            else
                b2[i/2]=b[i];

        sort(b2, b2+n/2);
        sort(b1, b1+(n+1)/2);

        sort(b, b+n);

        int ans=-1;
        for(int i=0; i<n; i++)
            if((i%2==0&&b[i]!=b1[i/2]) || (i%2==1&&b[i]!=b2[i/2]))
            {
                ans=i;
                break;
            }

        printf("Case #%d: ", kase);
        if(ans==-1)
        {
            printf("OK\n");
        }
        else
        {
            printf("%d\n", ans);
        }


    }

    return 0;
}
