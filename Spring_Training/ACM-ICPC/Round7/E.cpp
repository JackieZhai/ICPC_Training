#include <bits/stdc++.h>
using namespace std;



int n, m;
int a[107];


int main()
{
    scanf("%d%d", &n, &m);
    while(m--)
    {
        int buf;
        scanf("%d", &buf);
        for(int i=buf; i<=n; i++)
            if(a[i]==0)
                a[i]=buf;
    }
    for(int i=1; i<=n; i++)
    {
        if(i!=1)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");




    return 0;
}
