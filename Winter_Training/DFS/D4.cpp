/*
¡∑œ∞Ã‚£∫Red and Black_POJ 1979 
*/
#include <cstdio>
using namespace std;

char maze[25][25];
int W, H;
int sx, sy;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int count;

void dfs(int x, int y)
{
	for(int i=0; i<4; i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<W&&ny>=0&&ny<H&&maze[nx][ny]!='#'&&maze[nx][ny]!='@')
		{
			maze[nx][ny]='@';
			dfs(nx,ny);
			count++;
		}
	}
	return ;
}

int main()
{
	while(scanf("%d%d", &H, &W)!=EOF)
	{
		count=1;
		if(W==0&&H==0)
			break;
		getchar();
		for(int i=0; i<W; i++)
			gets(maze[i]);
		for(int i=0; i<W; i++)
			for(int j=0; j<H; j++)
				if(maze[i][j]=='@')
				{
					sx=i;
					sy=j;
					break;
				}
		dfs(sx, sy);
		printf("%d\n", count);
		
	}
	
	return 0;
}
