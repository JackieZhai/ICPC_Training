#include <bits/stdc++.h>
using namespace std;

int n;
const int MAX_N=107;
char word[MAX_N][17];
int v[MAX_N];
int mark[MAX_N];

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			getchar();
			scanf("%s", &word[i]);
			scanf("%d", &v[i]);
		}
		
		fill(mark, mark+n, false);
		
		int ans=0;
		for(int i=0; i<n; i++)
		{
			if(mark[i]==false)
			{
				int m1=v[i];
				int m2=0;
				mark[i]=true;
				for(int j=i+1; j<n; j++)
				{
					if(mark[j]==false)
					{
						if(strcmp(word[i], word[j])==0)
						{
							mark[j]=true;
							if(m1<v[j])
							{
								m2=m1;
								m1=v[j];
							}
							else if(m2<v[j])
								m2=v[j];
						}
					}
				}
				ans+=m1+m2;
			}
		}
		
		printf("%d\n", ans);
		
		
		
		
	}
	
	
	
	return 0;
}
