/*
�Թ������·����
	�����Թ��ĳ���SΪ��㡢GΪ�յ㣬#��ǽ�� 
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
//�������飬��ʾ������������� 
int d[MAX][MAX];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int bfs()
{
	queue<P> que;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			d[i][j]=INF;
	//�Ȱ����Ž�ȥ����������Ϊ�� 
	que.push(P(sx, sy));
	d[sx][sy]=0;
	
	//ֱ������û��Ԫ�أ�����·������ 
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

