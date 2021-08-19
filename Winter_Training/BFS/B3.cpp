/*
练习题：Cheese_AOJ 0558 
*/

#include <bits/stdc++.h>
using namespace std;

const int INF=100000000;
const int MAX=1000;

typedef pair<int, int> P;
int N, M;
int sx, sy;
int gx[10], gy[10];
char maze[MAX][MAX];
//设置数组，表示到起点的最近距离 
int d[MAX][MAX];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int bfs(int g)
{
	queue<P> que;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			d[i][j]=INF;
	//先把起点放进去，距离设置为零 
	que.push(P(sx, sy));
	d[sx][sy]=0;
	
	//直到队列没有元素，就无路可走了 
	while(que.size())
	{
		P p = que.front();
		que.pop();
		if(p.first==gx[g]&&p.second==gy[g])
			break;
		
		for(int i=0; i<4; i++)
		{
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<M&&maze[nx][ny]!='X'&&d[nx][ny]==INF)
			{
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second]+1;
			}
		}	
	}
	return d[gx[g]][gy[g]];
}

int main()
{
	int gn;
	scanf("%d%d%d", &N, &M, &gn);
	getchar();
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
			scanf("%c", &maze[i][j]);
		getchar();
	}
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			if(maze[i][j]=='S')
			{
				sx=i;
				sy=j;
			}
			if(maze[i][j]=='1')
			{
				gx[1]=i;
				gy[1]=j;
			}
			if(maze[i][j]=='2')
			{
				gx[2]=i;
				gy[2]=j;
			}
			if(maze[i][j]=='3')
			{
				gx[3]=i;
				gy[3]=j;
			}
			if(maze[i][j]=='4')
			{
				gx[4]=i;
				gy[4]=j;
			}
			if(maze[i][j]=='5')
			{
				gx[5]=i;
				gy[5]=j;
			}
			if(maze[i][j]=='6')
			{
				gx[6]=i;
				gy[6]=j;
			}
			if(maze[i][j]=='7')
			{
				gx[7]=i;
				gy[7]=j;
			}
			if(maze[i][j]=='8')
			{
				gx[8]=i;
				gy[8]=j;
			}
			if(maze[i][j]=='9')
			{
				gx[9]=i;
				gy[9]=j;
			}
		}
	
	int asw = bfs(1);
	for(int i=1; i<gn; i++)
	{
		sx=gx[i]; sy=gy[i];
		asw += bfs(i+1);
	}
	printf("%d\n", asw);
	
	
	return 0;
}

