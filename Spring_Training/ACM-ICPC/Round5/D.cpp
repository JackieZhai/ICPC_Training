#include <bits/stdc++.h>
using namespace std;

const int maxn=26*26*26*26;

int a[500005];
int vis[26][26][26][26];

int main()
{
    memset(vis,0,sizeof vis);
    a[1]=0, a[2]=0, a[3]=0;

    for(int i=4; i<=maxn+3; i++)
    {
        for(int j=25; j>=0; j--)
        {
            if(vis[a[i-3]][a[i-2]][a[i-1]][j]==0)
            {
                a[i]=j;
                vis[a[i-3]][a[i-2]][a[i-1]][j]=1;
                break;
            }
        }
    }

    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>maxn+3)
        {
            printf("Impossible\n");
        }
        else
        {
            for(int i=1; i<=n; i++)
                printf("%c", a[i]+97);
            printf("\n");
        }
    }

    return 0;
}
