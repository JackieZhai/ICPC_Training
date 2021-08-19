#include <bits/stdc++.h>
using namespace std;

int n, v;
int coun;
int mark[57];



int main()
{
    scanf("%d%d", &n, &v);
    for(int i=0; i<n; i++)
    {
        int k;
        scanf("%d", &k);
        for(int j=0; j<k; j++)
        {
            int buf;
            scanf("%d", &buf);
            if(buf<v)
            {
                mark[i]|=1;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(mark[i])
            coun++;
    }
    printf("%d\n", coun);
    bool flag=false;
    for(int i=0; i<n; i++)
    {
        if(mark[i] && !flag)
        {
            flag=true;
            printf("%d", i+1);
        }
        else if(mark[i])
        {
            printf(" %d", i+1);
        }
    }
    printf("\n");



    return 0;
}
