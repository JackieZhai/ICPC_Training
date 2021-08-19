/*
加练题：Biorhythms_POJ 1006
	韩信点兵。 
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int p, e, i, d;
	int kase=0;
	while(scanf("%d%d%d%d", &p, &e, &i, &d)!=EOF)
	{
		if(p==-1&&e==-1&&i==-1&&d==-1)
		{
			break;
		}
		kase++;
		
		int ans =  (5544*p+14421*e+1288*i-d+21252)%21252;
		if(ans==0)
			printf("Case %d: the next triple peak occurs in 21252 days.\n", kase);
		else
			printf("Case %d: the next triple peak occurs in %d days.\n", kase, ans);
	}
	
	return 0;
}
