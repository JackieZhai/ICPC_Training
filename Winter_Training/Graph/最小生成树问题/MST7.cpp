/*
��ϰ�⣺Out of Hay_POJ 2395 
	������Ҫ����С��������������Ȩֵ�ߡ� 
	ע��������ر�(��������Kruskalû��Ӱ��)�� 
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_V=2007;
const int MAX_E=10007; 

struct edge{
	int u, v, cost;
}; 
bool cmp(const edge& e1, const edge& e2)
{
	return e1.cost<e2.cost;
}

edge es[MAX_E];
int V, E;


//DUS start line

int par[MAX_V];//���� 
int hight[MAX_V];//���ĸ߶�

//��ʼ��n��Ԫ��
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		hight[i]=0;
	}
}

//��ѯ���ĸ�
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
}

//�ϲ�x��y�����ļ���
void unite(int x, int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return ;
	if(hight[x]<hight[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(hight[x]==hight[y])
			hight[x]++;
	}
}

//�ж�x��y�Ƿ�����ͬһ������
bool same(int x, int y)
{
	return find(x)==find(y);
}

//DUS end line 


int kruskal()
{
	sort(es, es+E, cmp);
	
	init(V);
	
	int res=0;
	for(int i=0; i<E; i++)
	{
		edge e=es[i];
		if(!same(e.u, e.v))
		{
			unite(e.u, e.v);
			if(res<e.cost)
				res=e.cost;
		}
	}
	
	return res;
}

int main()
{
	scanf("%d%d", &V, &E);
	for(int i=0; i<E; i++)
	{
		int f, t, c;
		scanf("%d%d%d", &f, &t, &c);
		es[i]=(edge){f, t, c};
	}
	
	printf("%d\n", kruskal());
	
	return 0;
}
