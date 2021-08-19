/*
	犯了一个十分严重的错误：
	A bank goes bankrupt if it is robbed, and you may assume that 
	all probabilities are independent as the police have very low funds. 
	这句话中“概率”相互独立的意思没有看明白，所以cost应该是计算1-的值，并且相互做乘法运算。
	
	由于double类型不好进行比较，所以要倒换value和cost。 
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
