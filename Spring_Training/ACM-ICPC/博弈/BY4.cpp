/**
��ϰ�⣺Cheat in the Game_POJ 3688
    ��ʤ��ʯͷ��ֻ�������ſ�Ƭ��Ͷ���
    �ذܣ�ʯͷ��ֻ��ż���ſ�Ƭ��϶���
    ƽ�֣����⿨Ƭ��϶��޷��õ�ʯͷ��
dp[i][1] = true��ʾʯͷ��Ϊi����������������ſ�Ƭ���
dp[i][0] = true��ʾʯͷ��Ϊi�����������ż���ſ�Ƭ���
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

        //���dp��żѡ��
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

        //ѡ��ֻ��������������
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
