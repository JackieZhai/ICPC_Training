/*
¡∑œ∞Ã‚£∫Ball_AOJ 0033
*/
#include <cstdio>
#include <cstring>
using namespace std;

int a[15];
int mark[15];
int count;

void dfs(int x)
{
	mark[x] = 1;
	if(x==9)
	{
		count++;
		return ;
	}
	for(int i=x+1; i<=9; i++)
		if(a[x]<a[i]&&mark[i]==0)
		{
			return dfs(i);
		}
		else
		{
			if(i==9)
				count++;
			continue;
		}
	return ;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		count=0;
		bool flag=false;
		memset(mark, 0, sizeof(mark));
		for(int i=0; i<10; i++)
			scanf("%d", &a[i]);
		for(int i=0; i<10; i++)
		{
			if(mark[i]==0)
				dfs(i);
		}
		if(count<=2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
