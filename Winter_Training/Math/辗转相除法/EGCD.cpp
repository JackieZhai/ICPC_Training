/*
��չŷ������㷨(Extended Euclidean Algorithm)��
	������⡰������x��yʹ��ax+by=gcd(a,b)�������⡣

Sample input:
	4 11   (a=4, b=11)
Sample output:
	3 -1  (3*a-1*b=1)
*/
#include <bits/stdc++.h>
using namespace std;

int extgcd(int a, int b, int& x, int& y)
{
    int d=a;
	if(b!=0)
	{
		d=extgcd(b, a%b, y, x);
		y-=(a/b)*x;
	}
	else
	{
		x=1;
		y=0;
	}
	return d;
}

int main()
{
	int a, b, x, y;
	scanf("%d%d", &a, &b);
	extgcd(a, b, x, y);
	printf("%d %d\n", x, y);
	return 0;
}
