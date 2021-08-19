/*
շת�����(Euclidean Algorithm)�����Լ��(GCD)��
	��������߶��ϸ��(���������Ϊ�����ĵ�)�ĸ�����
	
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
	if(xx==yx && yy==xy)//���д����������0
	{
		printf("0\n");
		return 0;
	}
	printf("%d\n", gcd(abs(xx-yx),abs(yy-xy))-1);
	
	return 0;
}
