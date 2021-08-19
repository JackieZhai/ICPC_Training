/*
���⣺Expedition_POJ 2431 

Ŀ����Ҫ����С�ļ��ʹ�����
���ԣ�����ģ��Ϊ��ȼ���þ��ڼ��͸��Ӻ���
����Ϊ������ĳ����վ�󣬾ͻ����һ�μ��͵ġ�Ȩ����(����������������)�� 
*/
#include <cstdio> 
#include <iostream> 
#include <queue>
#include <algorithm>
using namespace std;

int L, P, N;
pair<int, int> F[10005];

bool cmp(pair<int, int> a,pair<int, int> b)
{
	return a.first<b.first;
}

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d%d", &F[i].first, &F[i].second);
	scanf("%d%d", &L, &P);
	//Ϊ��д�������㣬�ѵ��յ�ľ����Ϊ�����ľ��� 
	for(int i=0; i<N; i++)
		F[i].first=L-F[i].first;
	
	//Ϊ��д�������㣬���ǰ��յ�Ҳ��Ϊ�Ǽ���վ
	F[N].first=L;
	F[N].second=0;
	
	sort(F, F+N+1, cmp);
	
	priority_queue<int> que;
	
	int ans=0, pos=0, tank=P;
	//������������Ѿ��ź������� 
	for(int i=0; i<=N; i++)
	{
		int d=F[i].first-pos;
		while(tank-d<0)
		{
			if(que.empty())//û��·������վȴû���� 
			{
				puts("-1");
				return 0;
			}
			tank+=que.top();//������͵ļ���վ 
			que.pop();
			ans++;
		}
		tank-=d;
		pos=F[i].first;
		que.push(F[i].second);
	}
	printf("%d\n", ans);
	
	return 0;
}
