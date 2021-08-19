#include <bits/stdc++.h>
using namespace std;


int n;
double a[1007], b[1007];
double c[1007];
int D;

int main()
{
	double ans;
	
	scanf("%d%d", &n, &D);
	for(int i=0; i<n; i++)
		scanf("%lf", &a[i]);
	for(int i=0; i<n; i++)
		scanf("%lf", &b[i]);
	for(int i=0; i<n; i++)
		c[i]=b[i]/a[i];
	
	while(true)
	{
		int maxi;
		double maxc=0;
		for(int i=0; i<n; i++)
		{
			if(maxc<c[i])
			{
				maxc=c[i];
				maxi=i;
			}
		}
		
		
		if(a[maxi]>=D)
		{
			ans+=b[maxi]*D/a[maxi];
			break;
		}
		else
		{
			D-=a[maxi];
			c[maxi]=0;
			ans+=b[maxi];
		}
	
	
	}
	
	printf("%.2lf\n", ans);
	
	return 0;
}
