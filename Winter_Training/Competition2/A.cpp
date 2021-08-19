//ÓÃmap¸üºÃ 
#include <bits/stdc++.h>
using namespace std;



int main()
{
	int n, buf, card1=0, card2=0, count1=0, count2=0;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &buf);
		if(card1==0)
		{
			card1=buf;
			count1++;
			continue;
		}
		else if(card2==0)
		{
			if(card1==buf)
			{
				count1++;
				continue;
			}
			card2=buf;
			count2++;
			continue;
		}
		else
		{
			if(card1!=buf&&card2!=buf)
			{
				printf("NO\n");
				return 0;
			}
			else if(card1==buf)
				count1++;
			else if(card2==buf)
				count2++;
		}
	}
	if(count1!=count2)
		printf("NO\n");
	else{
	printf("YES\n");
	printf("%d %d\n", card1,card2);
	}
	
	return 0;
}
