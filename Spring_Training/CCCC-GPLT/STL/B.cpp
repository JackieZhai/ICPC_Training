#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int num[100005];
priority_queue <int,vector<int>,greater<int>  > Q;

int main()
{
    ll b;int n,k;
    cin >> n >> k;
    cin >> b;
    for(int i=0;i<n;i++)
        cin >>num[i];
    ll sum(0);
    int ans=n--;

    while(!Q.empty())
        Q.pop();
    for(int i = n-k+1; i<n; i++)
    {
        if(i < 0) continue;
        sum += num[i];
        Q.push(num[i]);
    }

    for(int i = n-k;i>=0; i--)
    {
        sum += num[i];
        Q.push(num[i]);
        if(sum > b)
            ans = i+1;
        if(sum-Q.top() > b)
        {
            ans = 1;
            break;
        }
        sum -= Q.top();
        Q.pop();
    }

    cout<<ans<<endl;


    return 0;
}
