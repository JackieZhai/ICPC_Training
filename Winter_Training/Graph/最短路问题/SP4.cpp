/*
������������·����(Floyd-Warshall Algorithm)��
	��DP��⣬����ʽΪ��
d[0][i][j]=cost[i][j]
d[k][i][j]=min(d[k-1][i][j], d[k-1][i][k]+d[k-1][k][j]) 
���ɿ��ԸĽ�Ϊd[i][j]����ʽ�� 
	���Ӷ�: O(|V|^3)�� 
	���Դ�����Ǹ��������⣻���ж��Ƿ��и�Ȧ��ֻ��Ҫ�ж��Ƿ����d[i][i]<0�� 
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_V = 107; //�����ܲ����ö������Ƕ������󲻴� 
const int INF = 100007;

int d[MAX_V][MAX_V]; //��ʾ�ߵ�Ȩֵ�������ڵ�ʱ����ΪINF���޸��ߵ�ʱ����d[i][i]=0��
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
