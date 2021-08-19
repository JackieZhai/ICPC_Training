#include <cstdio>
#include <iostream>
using namespace std;


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	
	int ans=0;
    for(int i=2; i<=n; i++)
	{
        ans=(ans+m)%i;
    }
    ans++;
	
	printf("%d\n", ans);
	
	return 0;
}
