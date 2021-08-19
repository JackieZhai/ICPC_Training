/*
��ϰ�⣺Prime Path_POJ 3126 
*/

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_L=10007, MAX_SQRT_B=107;

///����ɸ��(Segment Sieve)��������ҿ�����[a,b)�ڵ�����
typedef long long ll;

bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

//������[a,b)�ڵ�����ʵ��ɸ����is_prime[i-a]=true��i������
void sieveSeg(ll a, ll b)
{
	for(int i=0; (ll)i*i<b; i++)
		is_prime_small[i]=true;
	for(int i=0; i<b-a; i++)
		is_prime[i]=true;
	
	for(int i=2; (ll)i*i<b; i++)
	{
		if(is_prime_small[i])
		{
			for(int j=2*i; (ll)j*j<b; j+=i)
				is_prime_small[j]=false; //ɸ[2,��b)
			for(ll j=max(2LL, (a+i-1)/i)*i; j<b; j+=i)
				is_prime[j-a]=false;  //ɸ[a,b)
		}
	}
}


int a, b;

const int INF=0x3f3f3f3f;
int d[MAX_L];

// ����BFS������·���� 
int bfs()
{
	queue<int> que;
	for(int i=0; i<MAX_L; i++)
		d[i]=INF;
	//�Ȱ����Ž�ȥ����������Ϊ�� 
	que.push(a);
	d[a]=0;
	
	//ֱ������û��Ԫ�أ�����·������ 
	while(que.size())
	{
		int p = que.front();
		que.pop();
		if(p==b)
			break;
		
		int g,s,b,q,temp;
		q=p/1000;
		b=p%1000/100;
		s=p%100/10;
		g=p%10;
		for(int i=1; i<=9; i++)
		{
			temp=g+s*10+b*100+i*1000;
			if(is_prime[temp-1000]==true&&d[temp]==INF)
			{
				que.push(temp);
				d[temp] = d[p]+1;
			}
		}
		for(int i=0; i<=9; i++)
		{
			temp=g+s*10+i*100+q*1000;
			if(is_prime[temp-1000]==true&&d[temp]==INF)
			{
				que.push(temp);
				d[temp] = d[p]+1;
			}
		}
		for(int i=0; i<=9; i++)
		{
			temp=g+i*10+b*100+q*1000;
			if(is_prime[temp-1000]==true&&d[temp]==INF)
			{
				que.push(temp);
				d[temp] = d[p]+1;
			}
		}	
		for(int i=1; i<=9; i+=2)
		{
			temp=i+s*10+b*100+q*1000;
			if(is_prime[temp-1000]==true&&d[temp]==INF)
			{
				que.push(temp);
				d[temp] = d[p]+1;
			}
		}
	}
	return d[b];
}


int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &a, &b);
		sieveSeg(1000,10000);
		int bf=bfs();
		if(bf==INF)
			printf("Impossible\n");
		else
			printf("%d\n", bf);
		
	}
	
	return 0;
}



