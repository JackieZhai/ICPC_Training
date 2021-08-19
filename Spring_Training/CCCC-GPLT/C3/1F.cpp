#include <bits/stdc++.h>
using namespace std;

int a[1007];


int main()
{
	int n;
	scanf("%d", &n);
	int ocount=0, ecount=0; 
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i]%2==0)
			ecount++;
		else
			ocount++;
	}
	
	printf("%d %d\n", ocount, ecount);
	
	
	return 0;
}
