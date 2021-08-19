/*
辗转相除法(Euclidean Algorithm)求最大公约数(GCD)：
	可以求解线段上格点(横纵坐标均为整数的点)的个数。
	
Sample input:
	1 11
	5 3
Sample output:
	3
*/
#include <bits/stdc++.h>
using namespace std; 

int gcd(int a, int b)
{
	if(b==0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int xx, xy, yy, yx;
	scanf("%d%d%d%d", &xx, &xy, &yx, &yy);
	if(xx==yx && yy==xy)//特判此种情况答案是0
	{
		printf("0\n");
		return 0;
	}
	printf("%d\n", gcd(abs(xx-yx),abs(yy-xy))-1);
	
	return 0;
}
