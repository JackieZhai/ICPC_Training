/**
练习题：Cheat in the Game_POJ 3688
    必胜：石头数只由奇数张卡片组和而成
    必败：石头数只由偶数张卡片组合而成
    平局：任意卡片组合都无法得到石头数
dp[i][1] = true表示石头数为i的情况可以由奇数张卡片组成
dp[i][0] = true表示石头数为i的情况可以由偶数张卡片组成
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF=0x3f3f3f3f;

int a[10007];
bool dp[100007][2];

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        if(n==0 && m==0)
            break;
        for(int i=0; i<=m; i++)
        {
            dp[i][0]=dp[i][1]=false;
        }
        for(int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }

        //组成dp奇偶选项
        for(int i=0; i<n;  i++)
        {
            for(int j=m; j>a[i]; j--)
            {
                if(dp[j-a[i]][0])
                    dp[j][1]=true;
                if(dp[j-a[i]][1])
                    dp[j][0]=true;
            }
            dp[a[i]][1]=true;
        }

        //选择只能组成奇数项的数
        int ans=0;
        for(int i=0; i<=m; i++)
        {
            if(dp[i][1]&&!dp[i][0])
                ans++;
        }
        printf("%d\n", ans);

    }



    return 0;
}
