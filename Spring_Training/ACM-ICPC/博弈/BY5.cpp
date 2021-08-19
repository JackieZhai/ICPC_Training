/**
练习题：A New Stone Game_POJ 1740
    奇数堆石子，先手可以决定后手的偶数必输态；
    偶数堆石子，若不是必输态可以制造必输态成为必赢态；
    必输态是所有都是两两相等的石子。
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int a[17];

int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;

        for(int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
        }

        if(n%2==0)
        {
            sort(a, a+n);
            bool flag=false;
            for(int i=0;  i<n-1; i+=2)
            {
                if(a[i]!=a[i+1])
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                printf("1\n");
            else
                printf("0\n");
        }
        else
        {
            printf("1\n");
        }
    }


    return 0;
}
