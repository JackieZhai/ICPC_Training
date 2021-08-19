/*
���������������(LCS)�� 
	ע������������У��������������У�����ֻҪ�����˳��ȡ� 
	���Ӷȣ�O(s.size() X t.size()) 
*/
#include <bits/stdc++.h>
using namespace std;

string s, t;

int dp[1007][1007];

void solve()
{
	for(int i=0; i<s.size(); i++)
		for(int j=0; j<t.size(); j++)	
			if(s[i]==t[j])
				dp[i+1][j+1]=dp[i][j]+1;
			else
				dp[i+1][j+1]=max(dp[i+1][j], dp[i][j+1]);
	
	printf("%d\n", dp[s.size()][t.size()]);
	
}

int main()
{
	getline(cin, s);
	getline(cin, t);
	
	solve();
	
	return 0;
	
}
