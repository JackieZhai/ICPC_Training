#include <bits/stdc++.h>
using namespace std;

int N, L;
int T;
set<char> lib[10];
set<string> words;
set<string>::iterator ite;
string buf;

string Next(string pre)
{
    string aft=pre;
    for(int i=L-1; i>=0; i--)
    {
        char ch=pre[i]+1;
        while(lib[i].count(ch)==0)
        {
            ch++;
            if(ch=='Z'+1)
                break;
        }
        if(ch!='Z'+1)
        {
            aft[i]=ch;
            break;
        }
    }

    return aft;
}
string Pref(string pre)
{
    string aft=pre;
    for(int i=L-1; i>=0; i--)
    {
        char ch=pre[i]-1;
        while(lib[i].count(ch)==0)
        {
            ch--;
            if(ch=='A'-1)
                break;
        }
        if(ch!='A'-1)
        {
            aft[i]=ch;
            break;
        }
    }

    return aft;
}

int main()
{
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++)
    {
        scanf("%d%d", &N, &L);
        getchar();
        for(int i=0; i<L; i++)
            lib[i].clear();
        words.clear();

        for(int i=0; i<N; i++)
        {
            cin>>buf;
            words.insert(buf);
        }
        for(ite=words.begin(); ite!=words.end(); ite++)
        {
            for(int j=0; j<L; j++)
            {
                lib[j].insert((*ite)[j]);
            }
        }

        int kinds=1;
        for(int i=0; i<L; i++)
            kinds*=lib[i].size();
        if(kinds==N)
        {
            printf("Case #%d: -\n", kase);
            continue;
        }

        bool flag=false;
        for(ite=words.begin(); ite!=words.end(); ite++)
        {
            string ans=Next(*ite);
           // cout<<"&&& "<<ans<<endl;
            if(words.count(ans)==0)
            {
                printf("Case #%d: ", kase);
                cout<<ans<<endl;
                flag=true;
                break;
            }
            ans=Pref(*ite);
            //cout<<"&&& "<<ans<<endl;
            if(words.count(ans)==0)
            {
                printf("Case #%d: ", kase);
                cout<<ans<<endl;
                flag=true;
                break;
            }
        }
        if(flag)
            continue;
    }



    return 0;
}
