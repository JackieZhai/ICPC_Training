/**
��ϰ�⣺Football Game_POJ 2315
    ���Ƿ��ֶ����ݽ��д���֮����Ŀ�ȼ��ڸ���n��ʯ�ӣ�
����ÿ��ʯ����ÿ�����ȡk��ʯ�ӣ�ÿ�����ѡȡm��ʯ�Ӷ��������Ĳ������⡣
�����������ǽ�ÿ��ʯ�ӶѶ�k+1ȡģ�����㣬
��������ֻ��ȡһ��ʯ���ϵ�ʯ�ӵ����������Ƕ����е�ʯ�Ӷѵ�sgֵ����xor����õ�sgֵ
����xor�ֳ�Ϊ������㣬ֻ���мӷ�������λ��
��������ѡȡm��ʯ�ӵĲ������ǵ�xor���Ƕ���m+1�����µİ�����㣬
�����������ǰ�λ�������sgֵ��ģ��m+1�����µİ�����㼴�ɵõ��𰸡�
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
