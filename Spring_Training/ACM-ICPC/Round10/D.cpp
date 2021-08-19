#include <bits/stdc++.h>
using namespace std;

pair<int, int> P[2007];
int n;


int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d%d", &P[i].first, &P[i].second);

    int ans=0;
    for(int i=1; i<=n-1; i++)
    {
        for(int j=i+1; j<=n-1; j++)
        {
            for(int k=j+1; k<=n; k++)
            {
                //cout<<i<<j<<k<<endl;
                //cout<<(P[k].first-P[i].first)*(P[k].second-P[i].second)<<endl;
                //cout<<(P[j].first-P[i].first)*(P[j].second-P[i].second)<<endl;
                if((P[j].first-P[i].first)*(P[k].second-P[i].second)-(P[k].first-P[i].first)*(P[j].second-P[i].second)!=0)
                    ans++;
            }
        }
    }


    printf("%d\n", ans);



    return 0;
}
