#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int dp[2007][2007];
int n, k;


int main()
{

    scanf("%d%d", &n, &k);

    for(int i=1; i<=n; i++)
        dp[i][1]=1;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=k; j++)
            for(int k=1; i*k<=n; k++)
            {
                dp[i*k][j]=(dp[i*k][j]+dp[i][j-1])%MOD;
            }

//    for(int i=1; i<=k; i++)
//    {
//        for(int j=1; j<=n; j++)
//            cout<<dp[j][i]<<" ";
//        cout<<endl;
//    }


    int ans=0;
    for(int i=1; i<=n;  i++)
    {
        ans=(ans+dp[i][k])%MOD;
    }
    printf("%d\n", ans);



    return 0;
}


#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int dp[2007][2007];
int n, k;


int main()
{

    scanf("%d%d", &n, &k);

    for(int i=1; i<=k; i++)
        dp[1][i]=1;
    for(int i=1; i<=n; i++)
        dp[i][1]=i;

    for(int i=2; i<=n; i++)
        for(int j=2; j<=k; j++)
            for(int k=1; k<=i; k++)
            {
                dp[i][j]=(dp[i][j]+dp[i/k][j-1])%MOD;
            }

//    for(int i=1; i<=k; i++)
//    {
//        for(int j=1; j<=n; j++)
//            cout<<dp[j][i]<<" ";
//        cout<<endl;
//    }


    printf("%d\n", dp[n][k]);



    return 0;
}
