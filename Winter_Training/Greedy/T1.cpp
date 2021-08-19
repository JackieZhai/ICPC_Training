/*
̰�Ķ�������
	���������Ҷ�ӽ������С����󣩵�Ԫ�أ��ɾ���������
	(Fence Repair_POJ3253)&&(Appleman and Toastman_CodeForces-462C) 
*/
#include <cstdio>
#include <queue>
using namespace std;



int main()
{
	long long int ans=0;
	int N;
	//��С�������е����ȶ��еķ�����
	priority_queue<int, vector<int>, greater<int> > que;
	
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		int buf;
		scanf("%d", &buf);
		que.push(buf);
	}
	
	while(que.size()>1)
	{
		int l1, l2;
		l1=que.top();
		que.pop();
		l2=que.top();
		que.pop();
		ans+=l1+l2;
		que.push(l1+l2);
	}
	printf("%lld\n", ans);
	
	
	return 0;
}
