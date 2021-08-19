/*
	To sort pair or >, use the third parameter of sort() function. 
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

bool cmp(const P &a, const P &b)
{
    if (a.first < b.first)
        return true;
    else return false;
}


int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int m;
		scanf("%d", &m);
		P p[55];
		for(int i=0; i<m; i++)
			scanf("%d%d", &p[i].first, &p[i].second);
		
		sort(p, p+m, cmp);
		
		
	    for(int i=0; i<m; i++){
		for(int j=0; j<p[i].second; j++)
		{
			printf(">+");
			for(int k=0; k<p[i].first-2; k++)
			{
				printf("-");
			}
			printf("+>");
			printf("\n");
		}
		printf("\n");
		}
		
		
	}
	
	return 0;
}
