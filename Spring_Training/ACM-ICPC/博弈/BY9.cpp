/**
练习题：Football Game_POJ 2315
    我们发现对数据进行处理之后，题目等价于给出n堆石子，
　　每堆石子中每次最多取k个石子，每次最多选取m个石子堆做操作的博弈问题。
　　首先我们将每堆石子堆对k+1取模简化运算，
　　对于只能取一堆石子上的石子的做法我们是对所有的石子堆的sg值进行xor运算得到sg值
　　xor又称为半加运算，只进行加法而不进位，
　　对于选取m堆石子的博弈我们的xor则是对于m+1进制下的半加运算，
　　所以我们按位计算这个sg值，模拟m+1进制下的半加运算即可得到答案。
*/
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N=30;
const double PI=acos(-1.0);

int n, m, l, r, a[N], sg[N];
int dis(int s)
{
    return (int)(s/(2*PI*r))+1;
}

bool solve()
{
    memset(sg,0,sizeof(sg));
    int k=dis(l);
    for(int i=0;i<n;i++)
    {
        int j=0;
        int g=dis(a[i])%k;
        while(g)
        {
            if(g%2==1)
                sg[j]++;
            j++;
            g/=2;
        }
    }

    for(int i=0;i<30;i++)
        if(sg[i]%(m+1))
            return 1;
    return 0;
}

int main()
{
    while(scanf("%d%d%d%d",&n,&m,&l,&r)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        puts(solve()?"Alice":"Bob");
    }


    return 0;
}
