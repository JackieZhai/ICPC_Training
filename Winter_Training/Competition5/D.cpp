#include <bits/stdc++.h> 
using namespace std;

//´ó°×4.2µÄ2 A Funny Game

int n, m;

int main()
{
	int T;
	scanf("%d\n", &T);
	for(int k=1; k<=T; k++)
	{
		scanf("%d%d", &n, &m);
		
		if(m==1)
		{
			if(n%2==1)
			{
				printf("Case %d: first\n", k);
			}
			else
			{
				printf("Case %d: second\n", k);
			}
			continue;
		}
		
		if(n<=m)
		{
			printf("Case %d: first\n", k);
		}
		else
		{
			printf("Case %d: second\n", k);
		}
	}
	
	return 0;
}
