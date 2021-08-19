#include <bits/stdc++.h>
using namespace std;

const int MAX_N=200007;


//DUS start line

int par[MAX_N];//父亲
int ran[MAX_N];//树的高度

//初始化n个元素
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		ran[i]=0;
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
	if(ran[x]<ran[y])
		par[x]=y;
	else
	{
		par[y]=x;
		if(ran[x]==ran[y])
			ran[x]++;
	}
}

//判断x和y是否属于同一个集合
bool same(int x, int y)
{
	return find(x)==find(y);
}

//DUS end line


int color[200007];
vector<int> ve[200007];
map<int, int> ma[200007];

int n, m, k;


int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=1; i<=n; i++)
        scanf("%d", &color[i]);
    init(n+1);
    while(m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if(!same(l, r))
            unite(l, r);
    }

    for(int i=1; i<=n; i++)
    {
        ve[find(i)].push_back(i);
    }

    int ans=0;
    for(int i=1;i<=n; i++)
    {
        if(!ve[i].size())
            continue;
        for(int j=0; j<ve[i].size(); j++)
        {
            ma[i][color[ve[i][j]]]++;
        }

        int maxColor=0;
        for(int j=0; j<ve[i].size(); j++)
        {
            maxColor=max(maxColor, ma[i][color[ve[i][j]]]);
        }
        int dif=ve[i].size()-maxColor;
        ans+=dif;
    }

    printf("%d\n", ans);

    return 0;
}
