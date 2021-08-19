/*
���⣺Crane_POJ 2991
	����һ�������RMQ��
	������i��ʾ��������vxi��vyi��������angi���������ӽ����chl��chr��
	��ô���У�
	vxi = vxchl+(cos(angi)*vxchr-sin(angi)*vychr)
	vyi = vychl+(sin(angi)*vxchr+cos(angi)*vychr) 
*/ 
#include <cstdio>
#define _USE_MATH_DEFINES  //C++
#include <cmath>
#include <algorithm>
using namespace std;

const int ST_SIZE=(1<<15)-1;
const int MAX_N=10007, MAX_C=10007;

//���� 
int N, C;
int L[MAX_N];
int S[MAX_C], A[MAX_N];

//�߶�����ά��������
double vx[ST_SIZE], vy[ST_SIZE];
double ang[ST_SIZE];

//Ϊ�˲�ѯ�Ƕȵı仯������ĵ�ǰ�Ƕȵ�����
double prv[MAX_N];

//��ʼ���߶���
//k�ǽ��ı�ţ�l��r��ʾ��ǰ����Ӧ����[l,r)����
void init(int k, int l, int r)
{
	ang[k]=vx[k]=0.0;
	if(r-l==1)
	{
		//Ҷ�ӽ��
		vy[k]=L[l]; 
	}
	else
	{
		int chl = k*2+1, chr=k*2+2;
		init(chl, l, (l+r)/2);
		init(chr, (l+r)/2, r);
		vy[k]=vy[chl]+vy[chr];
	}
}

//��s��s+1�ĽǶȱ�Ϊa
//v�ǽ��ı�ţ�l��r��Ӧ���ǵ�ǰ�����[l,r)����
void change(int s, double a, int v, int l , int r)
{
	if(s<=l)
		return ;
	else if(s<r)
	{
		int chl=v*2+1, chr=v*2+2;
		int m=(l+r)/2;
		change(s, a, chl, l, m);
		change(s, a, chr, m, r);
		if(s<=m)
			ang[v]+=a;
		
		double s=sin(ang[v]), c=cos(ang[v]);
		vx[v]=vx[chl]+(c*vx[chr]-s*vy[chr]);
		vy[v]=vy[chl]+(s*vx[chr]+c*vy[chr]);
	}
}

int main()
{
	while(scanf("%d%d", &N, &C)!=EOF)
	{
		for(int i=0; i<N; i++)
			scanf("%d", &L[i]);
		
		for(int i=0; i<C; i++)
			scanf("%d%d", &S[i], &A[i]);
		
		init(0, 0, N);
		for(int i=1; i<N; i++)
			prv[i]=M_PI;
			
		for(int i=0; i<C; i++)
		{
			int s=S[i];
			double a=A[i]/360.0*2*M_PI;
			
			change(s, a-prv[s], 0, 0, N);
			prv[s]=a;
			
			printf("%.2f %.2f\n", vx[0], vy[0]);
		}
		printf("\n");
	}
	
	return 0;
}
