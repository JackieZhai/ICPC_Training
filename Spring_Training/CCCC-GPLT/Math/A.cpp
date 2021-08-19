#include <cstdio>
#include <iostream>
using namespace std;


int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int count, ans;
		scanf("%d", &count);
		scanf("%d", &ans);
		for(int i=1; i<count; i++)
		{
			int buf;
			scanf("%d", &buf);
			ans=ans/gcd(ans, buf)*buf;
		}
		printf("%d\n", ans);
	}
	
	
	return 0;
}
