#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

set<string> dic;
char s[7];
string cmp;


int main()
{
    string buf;
    while(getline(cin, buf))
    {
        if(buf=="XXXXXX")
            break;
        dic.insert(buf);
    }
    while(getline(cin, buf))
    {
        if(buf=="XXXXXX")
            break;
        bool flag=false;
        int ssize=buf.size();
        for(int i=0; i<buf.size(); i++)
        {
            s[i]=buf[i];
        }
        for(int i=buf.size(); i<6; i++)
        {
            s[i]='\0';
        }
        sort(s, s+ssize);
        do{
            cmp=s;
            if(dic.count(cmp))
            {
                printf("%s\n", s);
                flag=true;
            }
        }while(next_permutation(s, s+ssize));
        if(!flag)
            printf("NOT A VALID WORD\n");
        printf("******\n");
    }




    return 0;
}
