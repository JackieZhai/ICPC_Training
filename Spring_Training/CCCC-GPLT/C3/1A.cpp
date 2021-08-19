#include <bits/stdc++.h>
using namespace std;

string num;
double ans;

int main()
{
	getline(cin, num);
	if(num[0]=='-')
    {
        int coun=0;
        for(int i=1; i<num.size(); i++)
        {
            if(num[i]=='2')
                coun++;
        }
        ans=(double)coun/(num.size()-1);
        ans*=1.5;
        if((num[num.size()-1]-'0')%2==0)
            ans*=2;
    }
    else
    {
        int coun=0;
        for(int i=0; i<num.size(); i++)
        {
            if(num[i]=='2')
                coun++;
        }
        ans=(double)coun/num.size();
        if((num[num.size()-1]-'0')%2==0)
            ans*=2;
    }
	printf("%.2lf%%", ans*100);


	return 0;
}
