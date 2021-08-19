#include <bits/stdc++.h>
using namespace std;


set<string> win, los;
int n;
set<string>::iterator ite, ite2;


int main()
{
    while(scanf("%d", &n)!=EOF)
    {
        getchar();
        if(n==0)
            break;
        win.clear();
        los.clear();
        for(int i=0; i<n; i++)
        {
            string buf;
            cin>>buf;
            win.insert(buf);
            cin>>buf;
            los.insert(buf);

            for(ite=los.begin(); ite!=los.end(); ite++)
            {
                ite2=win.find(*ite);
                if(ite2!=win.end())
                {
                    win.erase(ite2);
                }
            }

        }

        if(win.size()==1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }

    }



    return 0;
}
