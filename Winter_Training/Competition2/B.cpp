#include <bits/stdc++.h>
using namespace std;


char a[100005];


int main()
{
	int n;
	while(scanf("%d", &n)!=EOF)
	{
		if(n==0)
			break;
		
		getchar();
		scanf("%s", a);
		if(n%2==1)
		{	
			printf("-1\n");
			continue;
		}
		if(n==2)
		{
			printf("1\n");
			printf("1\n");
			continue;
		}
		
		int count1=0, count2=0;
		for(int i=0; i<n; i++)
		{
			if(a[i]=='H')
				count1++;
			if(a[i]=='T')
				count2++;	
		}
	
	
		int flag=false;
		int buf=0;
		int countf=0;
		int counts=0;
		for(int i=0; i<n/2; i++)
		{
			if(a[i]=='H')
				countf++;
			else if(a[i]=='T')
				counts++;
		}
		if(countf==count1/2&&counts==count2/2)
		{
			flag=true;
		}
		if(flag)
		{			
			printf("1\n");
			printf("%d\n", n/2);
			continue;
		}
		for(int i=1; i<=n/2; i++)
		{
			buf=i;
			if(a[i-1]=='H')
				countf--;
			else
				counts--;
			if(a[i+n/2-1]=='H')
				countf++;
			else
				counts++;
			
			if(countf==count1/2&&counts==count2/2)
			{
				flag=true;
				break;
			}
		}
		if(flag)
		{			
			printf("2\n");
			printf("%d %d\n", buf, n/2+buf);
		}
		else
			printf("-1\n");
		
	}
	
	return 0;
}
