#include <bits/stdc++.h>
using namespace std;

string s;
int counta=0;

bool check(int x, int y)
{
	
}

void dfs(int x, int y)
{
	if(counta!=0)
		return ;
	if(check(x, y))
		counta++;
	for(int i=x; i<=y; i++)
	{
		if(s[i]=='?')
		{
			s[i]='(';
			dfs(x,y);
			s[i]=')';
			dfs(x,y);
			s[i]='?';
		}
	}
	return ;
}



int main()
{
	getline(cin, s);
	
	int countb=0;
	for (int i = 0; i < s.size(); ++i)
	{
    	for (int j = i+1; j < s.size(); ++j)
		{
			if((j-i)%2==0)
				continue;
			dfs(i,j);
			if(counta>0)
			{
				countb++;
				printf("#%d %d\n", i, j);
			}
			counta=0;
		}
	}
	printf("%d\n", countb);
	
	return 0;
}
