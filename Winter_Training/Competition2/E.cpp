/*
��Ϊ���鼯��ϰ�⣺Wireless Network_POJ 2336 

�����ƽ����int(10e8)֮�ڵĻ����Ͳ��ÿ����ţ����⸡����� 
*/ 
#include <cstdio>
#include <cmath>
using namespace std;

const int MAX_N=1005;

//DUS start line

int par[MAX_N];//���� 
int rankd[MAX_N];//���ĸ߶�

//��ʼ��n��Ԫ��
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		rankd[i]=0;
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
	if(rankd[x]<rankd[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(rankd[x]==rankd[y])
			rankd[x]++;
	}
}

//�ж�x��y�Ƿ�����ͬһ������
bool same(int x, int y)
{
	return find(x)==find(y);
}

//DUS end line 


struct node{
	int x,y,r;
}c[MAX_N];

double dis(int a, int b)
{
	return sqrt((c[a].x-c[b].x)*(c[a].x-c[b].x)+(c[a].y-c[b].y)*(c[a].y-c[b].y));
}
  
int main()  
{  
	int n, d;
	scanf("%d%d", &n,&d);
	for(int i=1; i<=n; i++)
	{
		scanf("%d%d", &c[i].x, &c[i].y);
		c[i].r=0;
	}
	
	
	init(n);
	
	char buf;
	while(1)
	{
		getchar();
		buf=getchar();
		if(buf==EOF)
			break;
		if(buf=='O')
		{
			int q;
			scanf("%d", &q);
			c[q].r=1;
			for(int i=1; i<=n; i++)
			{
				if(c[i].r==1&&dis(i,q)<=d)
				{
					unite(q,i);
				}
			}
		}
		else if(buf=='S')
		{
			
			int q1;
			int q2;
			scanf("%d%d", &q1, &q2);
			if(same(q1,q2))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	 
    return 0;  
}  
