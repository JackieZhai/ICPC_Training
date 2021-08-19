#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;

map<string,string>word;
string ch,sh,help;
int i,j,k,l,m,n;
map<string,string> q;


int main()
{
    q.clear();
    j=0;
    while(cin>>ch,ch!="START");
    while(cin>>ch,ch!="END")
    {
        cin>>sh;
        q[sh]=ch;
    }
    cin>>sh;
    getchar();
    char s[11000];
    while(gets(s))
    {
        if(strcmp(s,"END")==0)
            break;
        char c[11000];
        j=0;
        int len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
                c[j++]=s[i];
            else
            {
                c[j]='\0';
                j=0;
                help=c;
                if(q.find(help)==q.end())
                    printf("%s",c);
                else
                    cout<<q[c];
                printf("%c",s[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
