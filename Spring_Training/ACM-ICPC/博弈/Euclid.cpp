#include <cstdio>
#include <algorithm>
using namespace std;


int a, b;

int main()
{
    while(scanf("%d%d", &a, &b)!=EOF)
    {
        if(a==0 && b==0)
            break;

        bool f=true;
        while(true)
        {
            if(a>b)
                swap(a, b);

            //b是a的倍数的时候胜负确定
            if(b%a==0)
                break;

            //如果是自由的情况胜负确定
            if(b-a>a)
                break;

            //胜负交换
            //奇数步Stan赢，偶数步Ollie赢
            b-=a;
            f=!f;
        }

        if(f)
            puts("Stan wins");
        else
            puts("Ollie wins");
    }



    return 0;
}
