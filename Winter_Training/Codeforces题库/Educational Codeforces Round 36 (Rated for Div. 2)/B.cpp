#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, n, pos, l, r, min=0;
	bool lf=false, rf=false;
	scanf("%d%d%d%d", &n, &pos, &l, &r);
	a=1;
	b=n;
	while(1)
	{
		if(a==l&&b==r)
			break;
		if(a==l)
			lf=true;
		if(b==r)
			rf=true;
		if(l==r)
		{
			if(lf||rf)
				min+=abs(pos-l)+1;
			else
				min+=abs(pos-l)+2;
			break;
		}
		if(!lf&&!rf)
		{
			if(abs(l-pos)<abs(r-pos))
			{
				lf=true;
				min+=abs(l-pos)+1;
				a=l;
				pos=l;
			}
			else
			{
				rf=true;
				min+=abs(r-pos)+1;
				b=r;
				pos=r;
			}
		}
		else if(!lf)
		{
			lf=true;
			min+=abs(l-pos)+1;
			a=l;
			pos=l;
		}
		else if(!rf)
		{
			rf=true;
			min+=abs(r-pos)+1;
			b=r;
			pos=r;
		}
	}
	printf("%d\n",min);
	return 0;
} 
