#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
int dp[10007];
ll n;

bool judge(vector<ll> a, int l, int r)
{
    int mul=a[l];
    for(int i=l+1; i<=r; i++)
    {
        if(a[i]!=a[i-1]+1)
        {
            return false;
        } else {
            mul*=a[i];
        }
    }

    if(n%mul==0)
        return true;
    else
        return false;
}

int main()
{

    cin>>n;

    vector<ll> a;
    a.push_back(n);

    for(ll i=2; i*i<=n; i++)
    {
        if(i*i==n)
        {
            a.push_back(i);
        }
        else if(n%i==0)
        {
            a.push_back(i);
            a.push_back(n/i);
        }
    }

    sort(a.begin(), a.end());

    int maxLen=1, maxPoint=0;
    for(int i=0; i<a.size(); i++)
        for(int j=i; j<a.size(); j++)
        {
            if(judge(a, i, j)&&(j-i+1>maxLen))
            {
                maxLen=j-i+1;
                maxPoint=i;
            }
        }

    cout<<maxLen<<endl;
    for(int i=0; i<maxLen; i++)
    {
        if(i!=0)
            cout<<"*";
        cout<<a[maxPoint]+i;
    }
    cout<<endl;


    return 0;
}
