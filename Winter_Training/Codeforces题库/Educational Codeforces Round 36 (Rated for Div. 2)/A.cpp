#include <bits/stdc++.h>
using namespace std;

void comp()
{
	
	
	
	
	return ;
}


int main()
{
	int a[105], n, k;
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i]==k)
		{
			printf("1\n");
			return 0;
		}
	}
	
	int sk = sqrt(k);
	for(int i=k-1; i>=1; i--)
	{
		if(k%i==0)
		{
			for(int j=0; j<n; j++)
				if(a[j]==i)
				{
					
					printf("%d\n", k/i);
					return 0;
				}
		}
	} 
	
	
	
	
	
	
	return 0;
} 
