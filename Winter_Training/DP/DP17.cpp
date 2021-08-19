/*
�����⣺Communication System_POJ 1018
	dp[i][j]��ʾǰi���豸����������Ϊjʱ����С���á� 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=105;
const int maxm=10005;

int b[maxn];
int p[maxn];
int dp[maxn][maxm];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
	{
        int n,m;
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        int maxb=0;
        for(int i=1;i<=n;i++)
		{
            scanf("%d",&m);
            for(int j=1;j<=m;j++)
			{
                scanf("%d%d",&b[j],&p[j]);
                maxb=max(maxb,b[j]);
            }
            
            if(i==1)
			{//��һ��ֱ�ӳ�ʼ��
                for(int j=1;j<=m;j++)
                    dp[i][b[j]]=p[j];
                continue;
            }
            
            for(int k=0;k<=maxb;k++)
			{
                if(dp[i-1][k]==-1)continue;
                for(int j=1;j<=m;j++)
				{
                    int mb=min(k,b[j]);//��ѡ���J������ʱ��ȡ��ǰ��С�Ĵ���
                    if(dp[i][mb]==-1)//������ִ���û�б����ϴﵽ����ֱ������һ���
                        dp[i][mb]=dp[i-1][k]+p[j];
                    else//�����������Ѿ���ֵ�ˡ���ѡ��С��
                        dp[i][mb]=min(dp[i][mb],dp[i-1][k]+p[j]);
                }
            }
        }
        
        double ans=0;
        for(int i=0;i<=maxb;i++)//����ÿһ�ִ���Ķ�Ӧ����С�ܼ۸�
            ans=max(ans,(1.0*i)/(double)dp[n][i]);
        printf("%.3f\n",ans);
        
    }
    
    return 0;
}
