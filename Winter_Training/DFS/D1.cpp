/*
���ֺ����⣺ 
	������a1, a2...���ж��Ƿ���Դ���ѡ����������ʹ�����ǵĺ�ǡ��Ϊk�� 
*/

#include <bits/stdc++.h>
using namespace std;


int a[1000];
int n, k;

bool dfs(int i, int sum)
{
	//�Ѿ�������ĩβ 
	if(i == n)
		return sum==k;
	//������a[i] 
	if(dfs(i+1, sum))
		return true;//ͬ��ͬ�� 
	//����a[i] 
	if(dfs(i+1, sum+a[i]))
		return true;//ͬ��ͬ��
	//�������������� 
	return false;
	
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &k);
	
	if(dfs(0, 0))
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}
