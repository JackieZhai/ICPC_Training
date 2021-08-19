#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[5007];
int count1=0, count2=0,count3=0;

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i]==1)
			count1++;
		else if(a[i]==2)
			count2++;
		else
			count3++;
	}
	
	int gr =  min(count1, min(count2, count3));
	printf("%d\n", gr);
	if(gr==0)
		return 0;
	int ind1 = 0, ind2=0, ind3=0;
	for(int i=0; i<gr; i++)
	{
		for(int j=ind1+1; j<=n; j++)
			if(a[j]==1)
			{
				
				printf("%d", j);
				ind1 = j;
				break;
			}
		for(int j=ind2+1; j<=n; j++)
			if(a[j]==2)
			{
				printf(" ");
				printf("%d", j);
				ind2 = j;
				break;
			}
		for(int j=ind3+1; j<=n; j++)
			if(a[j]==3)
			{
				printf(" ");
				printf("%d", j);
				ind3 = j;
				break;
			}
		printf("\n");
	}
	
	return 0;
}
