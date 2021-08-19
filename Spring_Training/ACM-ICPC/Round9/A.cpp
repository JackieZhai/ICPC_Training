#include <bits/stdc++.h>
using namespace std;


int mark[107];
int n;


int main()
{
    scanf("%d", &n);
    int p, q;
    scanf("%d", &p);
    for(int i=0; i<p; i++)
    {
        int buf;
        scanf("%d", &buf);
        mark[buf]=1;
    }
    scanf("%d", &q);
    for(int i=0; i<q; i++)
    {
        int buf;
        scanf("%d", &buf);
        mark[buf]=1;
    }
    bool flag=true;
    for(int i=1; i<=n; i++)
    {
        if(mark[i]==0)
        {
            flag=false;
            break;
        }
    }
    if(flag)
    {
        printf("I become the guy.\n");
    }
    else
    {
        printf("Oh, my keyboard!\n");
    }



    return 0;
}
