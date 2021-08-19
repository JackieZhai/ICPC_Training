/*
加练题：_HDU
	
*/
#include<stdio.h>
#include<string.h>
using namespace std;
struct INF{
    char name[106];
    int limit,use;
}a[20];
const int NMAX=1<<15|10;
const int inf=(1<<31)-1;
int time[NMAX],dp[NMAX],path[NMAX]; //time该状态所用时间 dp该状态被扣的分 
void out(int x)
{
    if(x==0)
        return;
    out(x-(1<<path[x]));
    printf("%s\n",a[path[x]].name);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(time,0,sizeof(time));
        for(int i=0;i<n;i++)
            scanf("%s%d%d",&a[i].name,&a[i].limit,&a[i].use);
        int choice=1<<n;
        for(int i=1;i<choice;i++)
        {
            dp[i]=inf;
            for(int j=n-1;j>=0;j--)
            {
                int num=1<<j;
                if(!(i&num))
                    continue;
                int score=time[i-num]+a[j].use-a[j].limit;
                if(score<0)
                    score=0;
                if(dp[i]>dp[i-num]+score)
                {
                    dp[i]=dp[i-num]+score;
                    time[i]=time[i-num]+a[j].use;
                    path[i]=j;
                }
            }

        }
        printf("%d\n",dp[choice-1]);
        out(choice-1);
    }
    return 0;
}
