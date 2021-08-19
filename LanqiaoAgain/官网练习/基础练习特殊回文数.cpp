#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    scanf("%d", &n);

    for(int i=10000; i<=99999; i++)
    {
        int w=i/10000, q=i%10000/1000, b=i%1000/100, s=i%100/10, g=i%10;
        if(w+q+b+s+g==n && w==g && q==s)
            printf("%d\n", i);
    }
    for(int i=100000; i<=999999; i++)
    {
        int sw=i/100000, w=i%100000/10000, q=i%10000/1000, b=i%1000/100, s=i%100/10, g=i%10;
        if(sw+w+q+b+s+g==n && sw==g && w==s && q==b)
            printf("%d\n", i);
    }



    return 0;
}
