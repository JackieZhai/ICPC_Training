/**
例题：Housewife Wind_POJ 2763
    树上两个节点a,b的距离可以转化为 dis[a] + dis[b] - 2*dis[lca(a,b)]
    其中 dis[i] 表示 i 节点到根的距离，由于每次修改一条边，树中在这条边下方的 dis[] 值全都会受到影响，这样每条边都对应这一段这条边的管辖区，
    可以深搜保存遍历该点的时间戳，ll[i] 表示第一次遍历到该点的时间戳， rr[i] 表示回溯到该点时的时间戳，
    这样每次修改边 i 的时候就可以对区间 [ ll[i], rr[i] ] 进行成段更新，
    成段更新的方式可以在 位置 ll[i] 上加一个权值，在位置 rr[i]+1 上减去这个权值，求和时，sum(ll[i]) 即为该点到根的距离。
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define clr(x)memset(x,0,sizeof(x))
#define maxn 200005
struct node
{
    int to,next,w,xu;
}e[1000000];
int tot;
int head[maxn];
void add(int s,int t,int wi,int xu)
{
    e[tot].xu=xu;
    e[tot].w=wi;
    e[tot].to=t;
    e[tot].next=head[s];
    head[s]=tot++;
}
int dp[maxn<<1][18];
int x[maxn<<1];
int d[maxn];
int r[maxn];
int v[maxn];
int f[maxn];
int ll[maxn];
int rr[maxn];
int g[maxn];
int n,m;
int min(int i,int j)
{
    return d[i]<d[j]?i:j;
}
void makermq(int nn)
{
    int i,j;
    for(i=0;i<nn;i++)
        dp[i][0]=i;
    for(j=1;(1<<j)<=nn;j++)
        for(i=1;i+(1<<j)-1<nn;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmq(int l,int r)
{
    int k=(int)(log((r-l+1)*1.0)/log(2.0));
    return min(dp[l][k],dp[r-(1<<k)+1][k]);
}
int cnt,ti;
void dfs(int u,int deep)
{
    v[u]=1;
    x[cnt]=u;
    d[cnt]=deep;
    r[u]=cnt++;
    ll[u]=++ti;
    int i,k;
    for(i=head[u];i;i=e[i].next)
    {
        k=e[i].to;
        if(!v[k])
        {
            g[e[i].xu]=k;
            dfs(k,deep+1);
            x[cnt]=u;
            d[cnt++]=deep;
        }
    }
    rr[u]=ti;
}
int tree[maxn];
int lowbit(int x)
{
    return (x)&(-x);
}
void update(int pos,int x)
{
    while(pos<=n)
    {
        tree[pos]+=x;
        pos+=lowbit(pos);
    }
}
int sum(int pos)
{
    int s=0;
    while(pos>0)
    {
        s+=tree[pos];
        pos-=lowbit(pos);
    }
    return s;
}
int edge[maxn];
int val[maxn];
int main()
{
    int i,st;
    while(scanf("%d%d%d",&n,&m,&st)!=EOF)
    {
        int a,b,c;
        clr(head);  clr(v);
        clr(f);     clr(tree);
        tot=1;
        ti=-1;
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            val[i]=c;
            edge[i]=c;
            add(a,b,c,i);
            add(b,a,c,i);
        }
        cnt=0;
        dfs(1,0);
        makermq(2*n-1);
        for(i=1;i<n;i++)
        {
            update(ll[g[i]],edge[i]);
            update(rr[g[i]]+1,-edge[i]);
        }
        int op;
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%d",&a,&b);
                update(ll[g[a]],-val[a]);
                update(rr[g[a]]+1,val[a]);
                update(ll[g[a]],b);
                update(rr[g[a]]+1,-b);
                val[a]=b;
            }
            else
            {
                scanf("%d",&a);
                int lca,d1,d2,d3;
                if(r[st]<=r[a])
                     lca=x[rmq(r[st],r[a])];
                else lca=x[rmq(r[a],r[st])];
                d1=sum(ll[st]);
                d2=sum(ll[a]);
                d3=sum(ll[lca]);
                st=a;
                printf("%d\n",d1+d2-2*d3);
            }
        }
    }
    return 0;
}
