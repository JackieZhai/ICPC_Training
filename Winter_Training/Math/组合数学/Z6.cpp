/*
加练题：Codeforces 933 B. A Determined Cleanup（数学）
*/
#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);
using namespace std;
typedef __int64 LL;
const int maxn = 1e5+10;

LL a[maxn];
LL ans[maxn];
LL k,p;

LL get(LL a1,int i)
{
    ans[i] = ((a1 % k) + k) % k;
    return (ans[i] - a1)/k;
}

int main()
{
    IO;
    cin>>p>>k;
    a[0] = p;
    for(int i=1; i<maxn; i++)
    {
        a[i] = get(a[i-1],i);
        if(!a[i])
        {
            cout<<i<<endl;
            for(int j=1; j<=i; j++)
                cout<<ans[j]<<" ";
            cout<<endl;
            break;
        }
    }
    return 0;
}