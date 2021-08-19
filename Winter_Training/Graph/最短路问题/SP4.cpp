/*
任意两点间最短路问题(Floyd-Warshall Algorithm)：
	用DP求解，递推式为：
d[0][i][j]=cost[i][j]
d[k][i][j]=min(d[k-1][i][j], d[k-1][i][k]+d[k-1][k][j]) 
依旧可以改进为d[i][j]的形式。 
	复杂度: O(|V|^3)。 
	可以处理边是负数的问题；而判断是否有负圈，只需要判断是否存在d[i][i]<0。 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 107; //弗法能不能用都看的是顶点数大不大 
const int INF = 100007;

int d[MAX_V][MAX_V]; //表示边的权值（不存在的时候设为INF，无负边的时候设d[i][i]=0）
int V, E;

void warshall_floyd()
{
	for(int k=0; k<V; k++)
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++)
				d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
}

int main()
{
	scanf("%d%d", &V, &E);
	
	for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
			d[i][j]=INF;
		d[i][i]=0;
	}
	
	
	for(int i=0; i<E; i++)
	{
		int buf1, buf2, buf3;
		scanf("%d%d%d", &buf1, &buf2, &buf3);
		d[buf1-1][buf2-1]=buf3; 
		d[buf2-1][buf1-1]=buf3;
	}
	
	
	warshall_floyd();
	printf("%d\n", d[0][V-1]);
	
	return 0;
}
