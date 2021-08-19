/*
º”¡∑Ã‚£∫Borg Maze_POJ 3026
	ShortestRoad(BFS) + MST(Prim) 
*/
#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include<stdio.h>
using namespace std;

const int inf = 1 << 20;

string *map;
int dis[110][110], x, y, alien[51][51], edge[110][110], num;
bool vis[51][51];
int Move[][2] = {0,-1,0,1,-1,0,1,0};

void bfs(int sx, int sy)
{
	queue<pair<int,int> >q;
	pair<int,int>p;
	p.first = sx, p.second = sy;
	q.push(p);
	memset(vis,false,sizeof(vis));
	vis[sx][sy] = true;
	memset(dis,0,sizeof(dis));
	while(!q.empty())
	{
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		if(alien[xx][yy])
			edge[ alien[sx][sy] ][ alien[xx][yy] ] = dis[xx][yy];
		for(int i = 0;i < 4;i++)
		{
			int mx = xx + Move[i][0];
			int my = yy + Move[i][1];
			if(mx<0||my<0||mx>=y||my>=x)
				continue;
			if(vis[mx][my] || map[mx][my] == '#')
				continue;
			vis[mx][my]  = true;
			dis[mx][my] = dis[xx][yy] + 1;
			p.first = mx, p.second = my;
			q.push(p);
		}
	}
}

int Prim()
{
	int Dis[110];
	bool book[110];
	book[1] = true;
	int t = 1, point, sum = 0, Min;
	for(int i = 1;i <= num;i++)
		Dis[i] = inf, book[i] = false;
	for(int k = 2;k <= num;k++)
	{
		Min = inf;
		for(int i = 2;i <= num;i++)
		{
			if(!book[i] && Dis[i] > edge[t][i])
				Dis[i] = edge[t][i];
			if(!book[i] && Dis[i] < Min)
			{
				Min = Dis[i];
				point = i;
			}
		}
		t = point;
		sum += Min;
		book[t] = true;
	}
	return sum;
}

int main()
{
    int N;
    cin>>N;
    while(N--)
	{
		memset(alien,0,sizeof(alien));
		num = 0;
		cin>>x>>y;
		string a;
		getline(cin,a);

		map = new string[y];
		for(int i = 0;i < y;i++)
		{
			getline(cin,map[i]);
			for(int j = 0;j < x;j++)
				if(map[i][j]=='S'||map[i][j] == 'A')
					alien[i][j] = ++num;
		}

		for(int i = 0;i < y;i++)
			for(int j = 0;j < x;j++)
				if(alien[i][j])
					bfs(i,j);
		cout<<Prim()<<endl;
	}
    return 0;
}
