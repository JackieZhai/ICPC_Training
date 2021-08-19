/*
���⣺ʳ����_POJ 1182 

���鼯�����ÿһ������Ԫ�ض���ͬʱ��������ͬʱ��������
��x-A��x-B��x-C��Ϊx, x+N, x+2*N�� 
*/
#include<cstdio>
using namespace std;

const int MAX_N=150005, MAX_K=100005;

//DUS start line

int par[MAX_N];//���� 
int rank[MAX_N];//���ĸ߶�

//��ʼ��n��Ԫ��
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		rank[i]=0;
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
	if(rank[x]<rank[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(rank[x]==rank[y])
			rank[x]++;
	}
}

//�ж�x��y�Ƿ�����ͬһ������
bool same(int x, int y)
{
	return find(x)==find(y);
}

//DUS end line 

int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];

void solve()
{
	//��ʼ�����鼯 
	//Ԫ��x, x+N, x+2*N�ֱ����x-A, x-B, x-C
	init(N*3);
	
	int ans=0;
	for(int i=0; i<K; i++)
	{
		int t=T[i];
		int x=X[i]-1, y=Y[i]-1;//�������Ϊ0~N-1�ķ�Χ
		
		//����ȷ�ı�� 
		if(x<0||N<=x||y<0||N<=y)
		{
			ans++;
			continue;
		}
		
		if(t==1)
		{
			//��x��y����ͬһ�ࡱ����Ϣ 
			if(same(x, y+N)||same(x, y+2*N))
			{
				ans++;
			}
			else
			{
				unite(x,y);
				unite(x+N,y+N);
				unite(x+N*2,y+N*2);
			}
		}
		else
		{
			//��x��y������Ϣ
			if(same(x,y)||same(x,y+2*N))
			{
				ans++;
			}
			else
			{
				unite(x,y+N);
				unite(x+N,y+2*N);
				unite(x+2*N,y);
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	scanf("%d%d", &N, &K);
	for(int i=0; i<K; i++)
		scanf("%d%d%d", &T[i], &X[i], &Y[i]);
	
	solve();
	
	return 0;
} 
