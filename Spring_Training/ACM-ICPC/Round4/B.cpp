#include <bits/stdc++.h>
using namespace std;

int k;
string inp;
vector<int> tra;
char pic[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string cal(string inp)
{
    tra.clear();

    for(int i=0; i<inp.size(); i++)
    {
        int buf=inp[i];
        int se[8];
        for(int j=0; j<8; j++)
        {
            se[j]=buf%2;
            buf/=2;
        }
        reverse(se, se+8);
        for(int j=0; j<8; j++)
        {
            tra.push_back(se[j]);
        }
    }

    string ans;
    int anspoint=0;
    int group=tra.size()/24;
    int resor=tra.size()%24;
    for(int i=0; i<group; i++)
    {
        int code[4];
        for(int j=0; j<4; j++)
        {
            code[j]=0;
            for(int k=0; k<6; k++)
            {
                code[j]+=tra[i*24+j*6+k]*pow(2, (6-k-1));
            }
            ans.push_back(pic[code[j]]);
        }
    }
    if(resor==8)
    {
        int ad1=0, ad2=0;
        for(int i=0; i<6; i++)
        {
            ad1+=tra[group*24+i]*pow(2, (6-i-1));
        }
        ans.push_back(pic[ad1]);
        for(int i=0; i<2; i++)
        {
            ad2+=tra[group*24+6+i]*pow(2, (6-i-1));
        }
        ans.push_back(pic[ad2]);
        ans.push_back('=');
        ans.push_back('=');
    }
    else if(resor==16)
    {
        int ad1=0, ad2=0, ad3=0;
        for(int i=0; i<6; i++)
        {
            ad1+=tra[group*24+i]*pow(2, (6-i-1));
        }
        ans.push_back(pic[ad1]);
        for(int i=0; i<6; i++)
        {
            ad2+=tra[group*24+6+i]*pow(2, (6-i-1));
        }
        ans.push_back(pic[ad2]);
        for(int i=0; i<4; i++)
        {
            ad3+=tra[group*24+12+i]*pow(2, (6-i-1));
        }
        ans.push_back(pic[ad3]);
        ans.push_back('=');
    }

    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++)
    {
        printf("Case #%d: ", kase);
        tra.clear();
        scanf("%d", &k);
        getchar();
        getline(cin, inp);

        string ans;
        ans=cal(inp);
        for(int i=0; i<k-1; i++)
        {
            ans=cal(ans);
        }


        cout<<ans<<endl;
    }






    return 0;
}
