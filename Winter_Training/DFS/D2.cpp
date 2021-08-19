/*
八连通问题：
	图中有多少个连接块？
	(Lake Counting_POJ No.2386) 
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
char field[105][105];
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void dfs(int x, int y)
{
	//走过之处变回原样，不再重走 
	field[x][y] = '.';
	
	for(int i=0; i<9; i++)
	{
		int nx=x+dx[i], ny=y+dy[i];
		if(0<=nx&&nx<N&&0<=ny&&ny<M&&field[nx][ny]=='W')
			dfs(nx, ny);
	}
	return ;
}

int main()
{
	scanf("%d%d", &N, &M);
	getchar();
	for(int i=0; i<N; i++)
		gets(field[i]);
	
	int res = 0;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			if(field[i][j]=='W')
			{
				dfs(i,j);
				res++;
			}
		}
	printf("%d\n", res);
	
		
	return 0;
}

