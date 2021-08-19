#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	scanf("%d", &n);
	m = (n-1)/5+1;
	int index = -1;
	
	while(m!=0)
	{
		m/=2;
		index++;
	}
	int head = pow(2, index);
	int start = (head-1)*5;
	int q = (n-start-1)/head;
	if(q==0)
		printf("Sheldon\n");
	else if(q==1)
		printf("Leonard\n");
	else if(q==2)
		printf("Penny\n");
	else if(q==3)
		printf("Rajesh\n");
	else if(q==4)
		printf("Howard\n");
	
	return 0;
}
