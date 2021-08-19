/*
加练题：Ideal Path_POJ 3967
	Smallest Lexicographically(BFS) + MST(Prim) 
	注意允许存在多重图。 
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=1e5+5,M=2e5+5,INF=1e9+5;

int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
    while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
    return x;
}

int n,m,u,v,w;

struct edge{
    int v,w,ne;
}e[M<<1];

int h[N],cnt=0;

void ins(int u,int v,int w)
{
    cnt++;
    e[cnt].v=v;e[cnt].w=w;e[cnt].ne=h[u];h[u]=cnt;
    cnt++;
    e[cnt].v=u;e[cnt].w=w;e[cnt].ne=h[v];h[v]=cnt;
}

int vis[N],q[N],head=1,tail=0;
int d[N];

void bfs1()
{
    q[++tail]=n;vis[n]=1;
    d[n]=1;
    while(head<=tail)
	{
        int u=q[head++];
        for(int i=h[u];i;i=e[i].ne)
		{
            int v=e[i].v;
            if(vis[v]) continue;
            vis[v]=1;
            d[v]=d[u]+1;
            q[++tail]=v;
        }
    }
}

int ans[N],lst[N],num=0;

void bfs2()
{
    memset(ans,127,sizeof(ans));
    head=1;tail=0;
    memset(q,0,sizeof(q));
    memset(vis,0,sizeof(vis));
    q[++tail]=1;
    while(head<=tail||num>=1)
	{
        int mn=INF,dis=0;num=0;
        while(head<=tail){
            int u=q[head++];dis=d[u]; 
            for(int i=h[u];i;i=e[i].ne)
			{
                int v=e[i].v,c=e[i].w;
                if(d[v]!=d[u]-1) continue;
                if(c>mn) continue;
                if(c<mn)
				{
                    num=0; mn=c;
                    lst[++num]=v;
                }
				else 
					lst[++num]=v;
            }
        }
        ans[dis]=mn;
        for(int i=1;i<=num;i++)
            if(!vis[lst[i]])
			{
				vis[lst[i]]=1;
				q[++tail]=lst[i];
			}
    }
}

int main() 
{
    n=read();m=read();
    for(int i=1;i<=m;i++){
        u=read();v=read();w=read();
        if(u!=v) ins(u,v,w);
    }
    bfs1();
    bfs2();
    printf("%d\n",d[1]-1);
    for(int i=d[1];i>1;i--) printf("%d ",ans[i]);
	
	return 0;
}
