#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    scanf("%d", &n);
    int maxn=-10001, minn=10001, sumn=0;
    while(n--)
    {
        int buf;
        scanf("%d", &buf);
        maxn=max(maxn, buf);
        minn=min(minn, buf);
        sumn+=buf;
    }
    printf("%d\n%d\n%d\n", maxn, minn, sumn);


    return 0;
}
