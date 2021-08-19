#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;
char maze[507][507];
int n, m;
int r1, c1, r2, c2;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};


void bfs()
{
	queue<P> que;
	//先把起点放进去
	que.push(P(r1, c1));
	
	//直到队列没有元素，就无路可走了 
	while(que.size())
	{
		P p = que.front();
		que.pop();
		
		for(int i=0; i<4; i++)
		{
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&maze[nx][ny]=='.')
			{
				maze[nx][ny]='X';
				que.push(P(nx,ny));
			}
			else if(nx==r2&&ny==c2&&maze[p.first][p.second]=='X')
			{
				printf("YES\n");
				exit(0);
			}
		}	
	}
	
}

int main()
{
	scanf("%d%d", &n, &m);
	getchar();
	for(int i=0; i<n; i++)
	{
		scanf("%s", maze[i]);
	}
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	r1--, c1--, r2--, c2--;
	
	bfs();
	printf("NO\n");
	
	return 0;
}
