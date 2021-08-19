#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	a=1;
	b=1;
	int n;
	scanf("%d", &n);
	if(n==1 || n==2)
	{
		printf("1\n");
		return 0;
	}
	for(int i=0; i<n-2; i++)
	{
		c=(a+b)%10007;
		a=b;
		b=c;
	}
	printf("%d\n", b);
	
	
	return 0;
}
