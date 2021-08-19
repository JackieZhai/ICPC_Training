#include <cstdio>
#include <cstring>
using namespace std;
///此题不宜用vector读写，会TLE

int a[900][900], b[900][900], mp[900][900];


int main()
{
    int n, i, j, k, x;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&x);
                a[i][j]=x%3;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&x);
                b[i][j]=x%3;
            }
        }
        memset(mp,0,sizeof(mp));
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=1;k<=n;k++)
                {
                    mp[i][k]+=a[i][j]*b[j][k];
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<n;j++)
            {
                printf("%d ",mp[i][j]%3);
            }
            printf("%d\n",mp[i][n]%3);
        }
    }
    return 0;
}
