#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


int n;
string a;

int main()
{
	scanf("%d", &n);
	getchar();
	getline(cin, a);
	
	if(n%3==1)
	{
		for(int i=0; i<n-2; i++)
		{
		printf("%c", a[i]);
		if((i+1)%3==0&&i!=0&&i!=n-1)
		{
			printf("-");
		}
		}
		printf("-");
		printf("%c%c", a[n-2], a[n-1]);
		printf("\n");
		return 0;
	}
	
	
	for(int i=0; i<n; i++)
	{
		printf("%c", a[i]);
		if((i+1)%3==0&&i!=0&&i!=n-1)
		{
			printf("-");
		}
	}
	printf("\n");
	
	
	
	
	return 0;
}
