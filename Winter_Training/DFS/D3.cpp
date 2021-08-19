/*
N皇后问题：(马拓展版)
	运用DFS后，进行判断(剪枝)，如果符合条件再继续搜索。
*/
#include <bits/stdc++.h>
using namespace std;

int tot=0;
int n;
int C[20];

void search(int cur)
{
	if(cur == n)
		tot++;
	else
		for(int i = 0;i<n;i++)
		{
			int ok=1;
			C[cur]=i;
			for(int j=0;j<cur;j++)
			{
				if(C[cur]==C[j] || cur-C[cur] == j-C[j] || cur+C[cur]==j+C[j])
				{
					ok = 0;
					break;
				}
//				if(j+1==cur&&C[j]+2==C[cur] || j+1==cur&&C[j]-2==C[cur] || j-1==cur&&C[j]+2==C[cur] || j-1==cur&&C[j]-2==C[cur] ||
//				   j+2==cur&&C[j]+1==C[cur] || j+2==cur&&C[j]-1==C[cur] || j-2==cur&&C[j]+1==C[cur] || j-2==cur&&C[j]-1==C[cur] )
//				{
//					ok = 0;
//					break;
//			    }
			}
			if(ok)
				search(cur+1);
		}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		//memset(C,0,sizeof(C));
		scanf("%d",&n);
		search(0);
		printf("%d\n",tot);
		tot = 0;
	}

	return 0;
}
