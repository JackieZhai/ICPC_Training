/*
º”¡∑Ã‚£∫Pride_Codeforces 891A
	
*/
#include <bits/stdc++.h>
using namespace std;

int a[2005];
const int INF=0x3f3f3f3f;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n;
    while(cin>>n)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
                cnt++;
        }
        if(cnt)
        {
            cout<<n-cnt<<endl;
        }
        else
        {
            int t=INF;
            for(int i=0;i<n;i++)
                for(int j=i,cur=0;j<n;j++)
                {
                    if((cur=gcd(cur,a[j]))==1)
                        t=min(t,j-i),j=n;
                }
            if(t==INF)
                cout<<"-1"<<endl;
            else
                cout<<t+n-1<<endl;
        }
    }
    return 0;
}
