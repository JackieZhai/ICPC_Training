/*
	����һ��ʮ�����صĴ���
	A bank goes bankrupt if it is robbed, and you may assume that 
	all probabilities are independent as the police have very low funds. 
	��仰�С����ʡ��໥��������˼û�п����ף�����costӦ���Ǽ���1-��ֵ�������໥���˷����㡣
	
	����double���Ͳ��ý��бȽϣ�����Ҫ����value��cost�� 
*/ 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node
{
    int m;
    double p;
}b[107];
int n;
double P;
double dp[100007];

int main ()
{
    int T;
    scanf("%d", &T);
    
    while(T--)
    {   
        scanf("%lf%d", &P, &n);
        int sum=0;
        
        for(int i=1; i<=n; i++)
        {
            scanf("%d%lf", &b[i].m, &b[i].p);
            sum+=b[i].m;
        }
        
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1; i<=n; i++)
            for(int j=sum; j>=b[i].m; j--)
            {
                dp[j]=max(dp[j], dp[j-b[i].m]*(1-b[i].p));
            }
            
        int i;
        for(i=sum; i>=0&&dp[i]<(1-P); i--);
        printf("%d\n", i);
    }
    return 0;
}
