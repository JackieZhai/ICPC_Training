#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;


int main()
{
	int kase=0;
	while(getline(cin, s))
	{
		if(s=="STOP")
			break;
		kase++;
		
		int t;
		if(s.length()%2==0)
			t=s.length()/2;
		else
			t=(s.length()+1)/2;
		
		int count=0;
		for(int i=0; i<t; i++)
		{
			if(s[i]==s[s.length()-i-1])
			{
				count++;
			}
			else
				break;
		}
		
		if(t==count)
		{
			printf("#%d: YES\n", kase);
		}
		else
		{
			printf("#%d: NO\n", kase);
		}
		
	}
	
	return 0;
}
