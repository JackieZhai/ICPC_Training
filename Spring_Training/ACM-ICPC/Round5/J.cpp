#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
const int f[4][2]={1, 0, -1, 0, 0, 1, 0, -1};
char ma[20][20];
int n, m;
struct node
{
    int x1, y1;
    int x2, y2;
}a[20];//保存m个通道的入口和出口坐标
struct Node
{
    int x,y,dis;
};
int b[20][20][20][20];//存的是一个通道的出口到其他通道的入口的最短距离，前两维表示出口坐标，后两维表示入口坐标
int ex, ey;
bool vis[20][20];
int dp[33000][20];

int bfs(int sx,int sy)
{
    memset(vis, false, sizeof(vis));
    queue<Node> q;
    Node st,en;
    st.x=sx, st.y=sy, st.dis=0;
    q.push(st);
    vis[sx][sy]=true;
    while(q.size())
    {
        st=q.front();
        q.pop();
        if(st.x==ex && st.y==ey) return st.dis;
        for(int i=0; i<4; i++)
        {
            int mx=st.x+f[i][0];
            int my=st.y+f[i][1];
            if(mx<1||mx>n||my<1||my>n||vis[mx][my]||ma[mx][my]=='#') continue;
            vis[mx][my]=true;
            en.x=mx,en.y=my;
            en.dis=st.dis+1;
            q.push(en);
        }
    }
    return inf;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1; i<=n; i++)
            scanf("%s",ma[i]+1);
        for(int i=0; i<m; i++)
            scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
        memset(b,inf,sizeof(b));
        for(int i=0; i<m; i++)//预处理出口到其他入口之间的最短距离
        {
            for(int j=0; j<m; j++)
            {
                if(i==j) continue;
                ex=a[j].x1,ey=a[j].y1;
                int d=bfs(a[i].x2,a[i].y2);
                b[a[i].x2][a[i].y2][a[j].x1][a[j].y1]=d;
            }
        }
        int N=1<<m;
        for(int i=0; i<N; i++)
            for(int j=0; j<m; j++)
            dp[i][j]=inf;
        for(int i=0; i<m; i++)
            dp[(1<<i)][i]=0;
        int ans=inf;
        for(int i=1; i<N; i++)
        {
            int flog=1;
            for(int j=0; j<m; j++)
            {
                if(!(i&(1<<j)))
                {
                    flog=0;
                    continue;
                }
                for(int k=0; k<m; k++)
                {
                    if(!(i&(1<<k))||j==k) continue;
                    dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+b[a[k].x2][a[k].y2][a[j].x1][a[j].y1]);
                }
            }
            if(flog)
            {
                for(int j=0;j<m;j++)
                    ans=min(ans,dp[i][j]);
            }
        }
        if(ans==inf)
            puts("-1");
        else
            printf("%d\n",ans);
    }
    return 0;
}
