///搜索相关

/*
迷宫的最短路径：
	输入迷宫的长宽，S为起点、G为终点，#是墙。
*/

#include <bits/stdc++.h>
using namespace std;

const int INF=100000000;
const int MAX=1000;

typedef pair<int, int> P;
int N, M;
int sx, sy;
int gx, gy;
char maze[MAX][MAX];
//设置数组，表示到起点的最近距离
int d[MAX][MAX];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int bfs()
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
		if(p.first==gx&&p.second==gy)
			break;

		for(int i=0; i<4; i++)
		{
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			if(nx>=0&&nx<N&&ny>=0&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==INF)
			{
				que.push(P(nx,ny));
				d[nx][ny] = d[p.first][p.second]+1;
			}
		}
	}
	return d[gx][gy];
}

int main()
{
	scanf("%d%d", &N, &M);
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
			if(maze[i][j]=='G')
			{
				gx=i;
				gy=j;
			}
		}

	int asw = bfs();
	printf("%d\n", asw);


	return 0;
}


/*
部分和问题：
	从整数a1, a2...中判断是否可以从中选出若干数，使得他们的和恰好为k。
*/

#include <bits/stdc++.h>
using namespace std;


int a[1000];
int n, k;

bool dfs(int i, int sum)
{
	//已经遍历到末尾
	if(i == n)
		return sum==k;
	//不加入a[i]
	if(dfs(i+1, sum))
		return true;//同对同错
	//加入a[i]
	if(dfs(i+1, sum+a[i]))
		return true;//同对同错
	//不管怎样都不行
	return false;

}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);

	if(dfs(0, 0))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
