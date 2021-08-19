#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	n = n-10;
	if(n<=0||n>=12)
		printf("0\n");
	else if(n==10)
		printf("15\n");
	else
		printf("4\n");
	return 0;
}
