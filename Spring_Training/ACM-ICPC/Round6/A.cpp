#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int p, q;

int main()
{
    while(scanf("%d%d", &p, &q)!=EOF)
    {
        printf("%d\n", p+q-gcd(p, q));
    }

    return 0;
}
