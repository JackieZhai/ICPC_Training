#include <bits/stdc++.h>
using namespace std;

map<string, string> cr;
map<string, string>::iterator ite;
int m, n;


int main()
{
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        string a, b;
        cin>>a>>b;
        if(a.size()>b.size())
        {
            cr[a]=b;
        }
    }
    for(int i=0; i<n; i++)
    {
        string c;
        cin>>c;
        if(i!=0)
            cout<<" ";
        ite=cr.find(c);
        if(ite!=cr.end())
        {
            cout<<cr[c];
        }
        else
        {
            cout<<c;
        }
    }
    cout<<endl;



    return 0;
}
