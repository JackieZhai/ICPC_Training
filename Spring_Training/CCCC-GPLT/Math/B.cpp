#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, B;
		scanf("%d%d", &n, &B);
		B=B%9973;
		while(n%B!=0)
		{
			n+=9973;
		}
		printf("%d\n", n/B);
	}
	
	
	
	return 0;
}
