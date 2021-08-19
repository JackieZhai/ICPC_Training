#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    scanf("%d", &n);
    bool flag=false;
    if(n%4==0)
    {
        flag=true;

        if(n%100==0)
        {
            flag=false;
        }

        if(n%400==0)
        {
            flag=true;
        }
    }

    if(flag)
        printf("yes\n");
    else
        printf("no\n");



    return 0;
}
