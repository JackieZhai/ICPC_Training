/*
	TLEԭ�򣺰�ÿһ��@����������BFS����ʵ��Y��M�ֱ���BFS(���μ���)��Ȼ���������¼���������Ƚϼ��ɡ�
*/


#include <bits/stdc++.h>
using namespace std;

char maze[205][205];
int n, m;
const int INF=100000000;
int dix[]={1,0,-1,0};
int diy[]={0,1,0,-1};
int mark[205][205]; 
int dy[205][205];
int dm[205][205]; 
int yx,yy,mx,my;
 
struct node  
{  
    int x,y;  
}a,temp;




void bfsy()
{
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			dy[i][j]=INF; 
	queue<node> que;
	//�Ȱ����Ž�ȥ����������Ϊ�� 
	a.x=yx;  
    a.y=yy;  
    dy[a.x][a.y]=0;
	que.push(a);
	
	//ֱ������û��Ԫ�أ�����·������
	while(que.size())
	{
		a = que.front();
		que.pop();
		
		for(int i=0; i<4; i++)
		{
			temp.x=a.x+dix[i];
			temp.y=a.y+diy[i];
			if(temp.x>=0&&temp.x<n&&temp.y>=0&&temp.y<m&&maze[temp.x][temp.y]!='#'&&dy[temp.x][temp.y]==INF)
			{
				que.push(temp);
				dy[temp.x][temp.y]=dy[a.x][a.y]+1;
			}
		}	
	}
}


void bfsm()
{
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			dm[i][j]=INF; 
	queue<node> que;
	//�Ȱ����Ž�ȥ����������Ϊ�� 
	a.x=mx;  
    a.y=my;  
    dm[a.x][a.y]=0;
	que.push(a);
	
	//ֱ������û��Ԫ�أ�����·������
	while(que.size())
	{
		a = que.front();
		que.pop();
		
		for(int i=0; i<4; i++)
		{
			temp.x=a.x+dix[i];
			temp.y=a.y+diy[i];
			if(temp.x>=0&&temp.x<n&&temp.y>=0&&temp.y<m&&maze[temp.x][temp.y]!='#'&&dm[temp.x][temp.y]==INF)
			{
				que.push(temp);
				dm[temp.x][temp.y]=dm[a.x][a.y]+1;
			}
		}	
	}
}

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		int ans=INF;
		getchar();
		for(int i=0; i<n; i++)
			scanf("%s", maze[i]);
		
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(maze[i][j]=='Y')
				{
					yx=i;
					yy=j;
				}
				else if(maze[i][j]=='M')
				{
					mx=i;
					my=j;
				}
		bfsy();
		bfsm();
		
		vector<int> K;
		
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
			{
				if(maze[i][j]=='@')
				{
					K.push_back(dy[i][j]+dm[i][j]);
				}
			}
		
		for(int i=0; i<K.size(); i++)
			if(ans>K[i])
				ans=K[i];
		printf("%d\n", ans*11);
		
		
		
	}
	
	
	return 0;
}
