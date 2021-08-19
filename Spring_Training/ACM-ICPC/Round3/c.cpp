#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans, len;
ll n;
char num[15];

void dfs(int point, ll sum)
{
    if(point==len)
    {
        if(n==sum)
            ans++;
        return ;
    }

    ll p=0;
    //cout<<"OK "<<point<<"  " <<sum<<endl;
    for(int i=point; i<=len; i++)
    {
        p*=10;
        p+=num[i]-'0';

        if(point==0)
        {
            dfs(i+1, sum+p);
        }
        else
        {
            dfs(i+1, sum+p);
            dfs(i+1, sum-p);
        }

    }


}

int main()
{
    while(scanf("%s %lld", num, &n)!=EOF)
    {
        ans=0;
        len=strlen(num);
        dfs(0, 0);
        printf("%d\n", ans);
    }




    return 0;
}
