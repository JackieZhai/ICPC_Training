/*
加练题：Code_POJ 1850
	Word Index_POJ 1496 同理，细节上有些许的不同。 

*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
string s;

int main()
{
	getline(cin, s);
	
	for(int i=0; i<s.size()-1; i++)
	{
		if(s[i]>=s[i+1])
		{
			printf("0\n");
			exit(0);
		}
	}
	
	ll c[27][27];
	for(int i = 0; i < 27; i++)
	{
		c[i][0] = 1;
		c[i][i] = 1;
	}
	for(int i = 1; i < 27; i++)
		for(int j = 1; j < i; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];
	
	
	int n=s.size();
	ll ans=0;
	for(int i=1; i<n; i++)
	{
		ans+=c[26][i];
	}
	
	for(int i=0;i<n;i++)
    {
        char ch= (!i)?'a':s[i-1]+1;
        while(ch<=s[i]-1)
        {
            ans+=c['z'-ch][n-1-i];
            ch++;
        }
    }
    ans++;
	
	printf("%I64d\n", ans);
	
	return 0;
}
