#include <bits/stdc++.h>
using namespace std;


int D;
string P;

int cal()
{
    int ret=0;
    int power=1;
    for(int i=0; i<P.size(); i++)
    {
        if(P[i]=='C')
        {
            power*=2;
        }
        else
        {
            ret+=power;
        }
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++)
    {
        printf("Case #%d: ", kase);
        scanf("%d", &D);
        getchar();
        cin>>P;

        int ans=0;
        bool flag=false;


        while(cal()>D)
        {
            int p=P.size()-1;
            while(!(P[p]=='S' && P[p-1]!='S'))
            {
                p--;
                if(p<=0)
                {
                    flag=true;
                    break;
                }
            }



            if(flag)
            {
                ans=-1;
                break;
            }
            else
            {
                swap(P[p], P[p-1]);
                ans++;
            }
        }

        if(ans==-1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);

    }




    return 0;
}
