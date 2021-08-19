#include <bits/stdc++.h>
using namespace std;


int p, q;
int l, r;
int Z[57][2], X[57][2];

bool jud(int x1, int y1, int x2, int y2)
{
    if(x1<=y2 && y1>=x2)
        return true;
    else
        return false;
}


int main()
{
    scanf("%d%d%d%d", &p, &q, &l, &r);
    for(int i=0; i<p; i++)
    {
        scanf("%d%d", &Z[i][0], &Z[i][1]);
    }
    for(int i=0; i<q; i++)
    {
        scanf("%d%d", &X[i][0], &X[i][1]);
    }
    int ans=0;
    for(int k=l; k<=r; k++)
    {
        bool flag=false;
        for(int i=0; i<p; i++)
        {
            for(int j=0; j<q; j++)
            {
                if(jud(Z[i][0], Z[i][1], X[j][0]+k, X[j][1]+k))
                {
                    //cout<<i<<" "<<j<<" "<<k<<endl;
                    flag=true;
                    ans++;
                    break;
                }
            }
            if(flag)
                break;
        }
    }
    printf("%d\n", ans);



    return 0;
}
