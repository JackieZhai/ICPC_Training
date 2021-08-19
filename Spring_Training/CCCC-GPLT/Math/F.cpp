#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX_N=20007;
int s[MAX_N];

int main()
{
	int n,m,maxn,i,j,ans;
	memset(s,0,sizeof(s));
	s[1]=1;
	
	for(i=2; i<MAX_N; i++)
	{
		if(s[i]==0)
		for(j=i;j<MAX_N;j+=i)
		{
			s[j]=i;
		}
	}
	
	while(cin>>n)
	{
		maxn=-1;
		while(n--)
		{
			cin>>m;
			if(s[m]>maxn)
			{
				maxn=s[m];
				ans=m;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
	
}



