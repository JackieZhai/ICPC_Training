#include <bits/stdc++.h> 
using namespace std;

const int INF=0x3f3f3f3f;
int p;
int dp[500007];
int a[500007]; 

int main()
{
	int kase=0;
	while(scanf("%d", &p)!=EOF)
	{
		kase++;
		for(int i=0; i<p; i++)
		{
			int buf1, buf2;
			scanf("%d%d", &buf1, &buf2);
			a[buf1-1]=buf2;
		}
		//转化为求LIS问题 
		fill(dp, dp+p, INF); 
		for(int i=0; i<p; i++)
		{
			*lower_bound(dp, dp+p, a[i]) = a[i]; 
		}
		int ans=lower_bound(dp, dp+p, INF)-dp;
		if(ans==1)
			printf("Case %d:\nMy king, at most %d road can be built.\n\n", kase, ans);
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n", kase, ans);
		
		
	}
	
	
	return 0;
}
