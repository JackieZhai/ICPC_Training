/*
例题：Saruman's Army_POJ 3069

贪心模型的建立就是从最左点开始，不断找最远的地方作为标记，直到结束；
注意此题的各种边界条件(假设标记点此处的点距离标记点为0) 
*/
#include <cstdio> 
#include <iostream> 
#include <algorithm>
using namespace std; 

int main()
{
	int R, N;
	int X[1005];
	while(scanf("%d%d", &R, &N)!=EOF)
	{
		if(R==-1&&N==-1)
			break;
		for(int i=0; i<N; i++)
			scanf("%d", &X[i]);
		
		sort(X, X+N);
		
		int i=0, ans=0;
		while(i<N)
		{
			int s=X[i++];
			while(i<N && X[i]<=s+R)
				i++;
			int p=X[i-1];
			while(i<N && X[i]<=p+R)
				i++;
			
			ans++;
		}
		printf("%d\n", ans);
		
	}
	
	
	return 0; 
}
