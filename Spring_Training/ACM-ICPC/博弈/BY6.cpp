/**
��ϰ�⣺Nim_POJ 2975
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1007];

int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;

        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);

        int x=0;
        for(int i=0; i<n; i++)
            x^=a[i];

        int ans=0;
        for(int i=0; i<n; i++)
        {
            if((x^a[i])<a[i]) //��֤S^a[i]<a[i]����ת���ذ�̬�Ĳ����ǺϷ���
                ans++;
        }
        printf("%d\n", ans);
    }



    return 0;
}
