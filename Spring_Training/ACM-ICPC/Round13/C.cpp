#include <bits/stdc++.h>
using namespace std;

const int MAX_P=100007;

int P;
int a[MAX_P];

void solve()
{
    set<int> all;
    for(int i=0; i<P; i++)
    {
        all.insert(a[i]);
    }
    int n=all.size();

    int s=0, t=0, num=0;
    map<int, int> coun;
    int res=P;
    while(true)
    {
        while(t<P && num<n)
        {
            if(coun[a[t++]]++==0)
                num++;
        }
        if(num<n)
            break;
        res=min(res, t-s);
        if(--coun[a[s++]]==0)
            num--;
    }
    printf("%d\n", res);
}

int main()
{
    scanf("%d", &P);
    getchar();
    for(int i=0; i<P; i++)
        scanf("%c", &a[i]);

    solve();


    return 0;
}
