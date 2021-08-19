#include <bits/stdc++.h>
using namespace std;




int main()
{
    for(int i=1000; i<=9999; i++)
    {
        int q=i/1000, b=i%1000/100, s=i%100/10, g=i%10;
        if(q==g && b==s)
            printf("%d\n", i);
    }




    return 0;
}
