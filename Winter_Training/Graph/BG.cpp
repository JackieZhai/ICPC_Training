/*
����ͼ�ж���
���壺1��û�������߻�·��
	  2����Ϊ�����֣��乫������û�бߡ�
��أ���ɫ���⣻
	  ����ͼƥ�䣨�������㷨�ȣ��� 
*/ 
#include <bits/stdc++.h>
using namespace std;

const int MAX_V=1000;

vector<int> G[MAX_V]; //ͼ���ڽӱ�ʵ�֣��±�Ϊʼ�ߣ�ֵ���ձ�
int V, E;
int color[MAX_V];
	
bool dfs(int v, int c)
{
	color[v]=c;
	for(int i=0; i<G[v].size(); i++)//�������ڽ�� 
	{
		if(color[G[v][i]]==c)
			return false;
		if(color[G[v][i]]==0 && !dfs(G[v][i], -c))
			return false;//false�Ĵ��ݽ��м�֦ 
	}
	return true;//���б߶��Ѿ�Ⱦ��ɫ�� 
}

void solve()
{
	for(int i=0; i<V; i++)
	{
		if(color[i]==0)
		{
			if(!dfs(i, 1))//������Ⱦ��1ɫ�������ڶ���Ⱦ��-1ɫ
			{
				printf("NO\n");
				return ;
			}
		}
	}
	printf("YES\n");
}

int main()
{
	scanf("%d%d", &V, &E);
	for(int i=0; i<E; i++)
	{
		int s, t;
		scanf("%d%d", &s, &t);
		G[s].push_back(t);
		G[t].push_back(s);//����ͼ���ߵ���ϵ��Ҫ����	
	}
	 
	solve(); 
	
	return 0;
}
