#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
const int MAX_N=100007;
char ansa[MAX_N][2];

//DUS start line

int par[MAX_N];//父亲 
int ranks[MAX_N];//树的高度

//初始化n个元素
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		ranks[i]=0;
	}
}

//查询树的根
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
}

//合并x和y所属的集合
void unite(int x, int y)
{
	x=find(x);
	y=find(y);
	if(x==y)
		return ;
	if(ranks[x]<ranks[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(ranks[x]==ranks[y])
			ranks[x]++;
	}
}

//判断x和y是否属于同一个集合
bool same(int x, int y)
{
	return find(x)==find(y);
}

//DUS end line 



int main()
{
	scanf("%d", &n);
	string a, b;
	getchar();
	getline(cin, a);
	getline(cin, b);
	
	init(256);
	int ans=0;
	int index=0;
	
	
	for(int i=0; i<n; i++)
	{
		if(!same(a[i], b[i]))
		{
			unite(a[i], b[i]);
			ans++;
			ansa[index][0]=a[i];
			ansa[index][1]=b[i];
			index++;
		}
		
	}
	
	
	printf("%d\n", ans);
	for(int i=0; i<index; i++)
	{
		printf("%c %c\n", ansa[i][0], ansa[i][1]);
	}
	
	return 0;
}
