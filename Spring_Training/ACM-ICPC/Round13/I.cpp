#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int coun;
char str[10007];
set<string> se;

int minRepre()
{
    int n = strlen(str);
    int i = 0,j = 1, k = 0;
    while(i<n && j<n && k<n)
    {
        int t = str[(i+k)%n] - str[(j+k)%n] ;
        if(t == 0)
            k++;
        else
        {
            if(t>0)
                i+=k+1;
            else
                j+=k+1;
            if(i==j)
                j++;
            k = 0;
        }
    }
    return i < j ? i : j;
}



int main()
{

    while(scanf("%d", &coun)!=EOF)
    {
        se.clear();
        int ans=0;
        getchar();
        while(coun--)
        {
            scanf("%s", str);
            int len=strlen(str);
            int les=minRepre();
            string s;
            for(int i=les; i<len; i++)
                s.push_back(str[i]);
            for(int i=0; i<les; i++)
                s.push_back(str[i]);
            if(!se.count(s))
            {
                ans++;
                se.insert(s);
            }
        }
        printf("%d\n", ans);
    }





    return 0;
}
