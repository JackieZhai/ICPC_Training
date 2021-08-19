#include <bits/stdc++.h>
using namespace std;

const int MAX_N=100007;

int n, a, b;
int num[MAX_N];
map<int, int> m; //reverse of num

//DUS
int par[MAX_N];
int ran[MAX_N];
void init(int n)
{
	for(int i=0; i<n; i++)
	{
		par[i]=i;
		ran[i]=0;
	}
}
int find(int x)
{
	if(par[x]==x)
		return x;
	else
		return par[x]=find(par[x]);
}
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
bool same(int x, int y)
{
	return find(x)==find(y);
}
//DUS


int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &num[i]);
        m[num[i]]=i;
    }

    init(n+7);//n->set(a-x), n+1->set(b-x)

    for(int i=0; i<n; i++)
    {
        int am, bm;
        if(m.find(a-num[i])!=m.end())
        {
            am=m[a-num[i]];
        }
        else
        {
            am=-1;
        }
        if(m.find(b-num[i])!=m.end())
        {
            bm=m[b-num[i]];
        }
        else
        {
            bm=-1;
        }
        //cout<<am<<" "<<bm<<endl;
        if(am!=-1)
            unite(i, am);
        else
            unite(i, n+1);
        if(bm!=-1)
            unite(i, bm);
        else
            unite(i, n);
    }
    if(same(n, n+1))
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
        for(int i=0; i<n; i++)
        {
            if(i!=0)
                printf(" ");
            if(same(n, i))
                printf("0");
            else //此处不能写"else if(same(n+1, i)"，因为这样全在一个集合情况就会WA
                printf("1");
        }
        printf("\n");
    }


    return 0;
}
