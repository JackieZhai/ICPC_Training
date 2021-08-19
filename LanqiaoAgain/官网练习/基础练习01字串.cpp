#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n=0;
    while(n<32)
    {
        int p=n;
        int ans[5];
        for(int i=0; i<5; i++)
        {
            ans[4-i]=p%2;
            p/=2;
        }
        for(int i=0; i<5; i++)
            printf("%d", ans[i]);
        printf("\n");


        n++;
    }



    return 0;
}
