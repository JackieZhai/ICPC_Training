/*
	�ؼ������ж�ÿһ�����һ��1��λ�á� 
*/

#include <bits/stdc++.h>
using namespace std;

const int MAX_N=47;
int N;
int M[MAX_N][MAX_N];

int a[MAX_N];

int main()
{
//	freopen("A-small-practice.in", "r", stdin);
//	freopen("A-small-practice.out", "w", stdout);
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for(int k=1; k<=T; k++)
	{
		scanf("%d", &N);
		getchar();
		for(int i=0; i<N; i++)
		{
			string buf;
			getline(cin, buf);
			for(int j=0; j<N; j++)
			{
				M[i][j]=buf[j]-'0';
			}
		}
		
		int res=0;
		for(int i=0; i<N; i++)
		{
			a[i]=-1; //�����i�в���1���͵���-1����
			for(int j=0; j<N; j++)
			{
				if(M[i][j]==1)
				{
					a[i]=j;
				}
			}
		}
		for(int i=0; i<N; i++)
		{
			int pos=-1; //Ҫ�ƶ�����i�е���
			for(int j=i; j<N; j++)
			{
				if(a[j]<=i)
				{
					pos=j;
					break;
				}
			}
			for(int j=pos; j>i; j--)
			{
				swap(a[j], a[j-1]);
				res++;
			}
		}
		printf("Case #%d: %d\n", k, res);
		
		
		
		
		
	}
	
	
	return 0;
}
