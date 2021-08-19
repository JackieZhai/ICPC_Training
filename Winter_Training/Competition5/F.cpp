/*
问题转化为：最小的大于1的k满足：10^k = 1 (mod num)，就是循环节长度。 
    其中num是要剔除2和5的所有因子的。 
*/
#include <bits/stdc++.h> 
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int ans, anslen=0;	
	for(int i=n; i>=1; i--)
	{
		int num=i;
		while(num%2==0)
			num/=2;
		while(num%5==0)
			num/=5;
		
		int res=1;
		for(int k=1; k<=num; k++)
		{
			res*=10;
			res%=num;
			if(res==1)
			{
				if(anslen<k)
				{
					anslen=k;
					ans=num;
					break;
				}
				else
					break;
			}
			else if(res==0)
			{
				break;
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}
