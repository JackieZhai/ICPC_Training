#include <bits/stdc++.h>
using namespace std;

string a;

int main()
{
    int coun=0;
    while(getline(cin, a))
    {
        if(a.size()<4)
            continue;
        for(int i=0; i<a.size()-3; i++)
        {
            if(a[i]=='D'||a[i]=='d')
                if(a[i+1]=='O'||a[i+1]=='o')
                    if(a[i+2]=='G'||a[i+2]=='g')
                        if(a[i+3]=='E'||a[i+3]=='e')
                            coun++;
        }
    }

    printf("%d\n", coun);


    return 0;
}

