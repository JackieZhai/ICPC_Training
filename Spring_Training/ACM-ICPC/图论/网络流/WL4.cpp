/**
例题：Dining_POJ 3281
    关注多目标规划的建图方法
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


const int INF=0x3f3f3f3f;
const int MAX_V=1007;

//用于表示边的结构体(终点、容量、反向边)
struct edge{
    int to, cap, rev;
};

vector<edge> G[MAX_V]; //图的邻接表表示
int level[MAX_V]; //顶点到源点的距离标号
int iter[MAX_V]; //当前弧，在其之前的边已经没有用了

//向图中增加一条从s到t的容量为cap的边
void add_edge(int from, int to, int cap)
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

//通过BFS计算从源点出发的距离标号
void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(int i=0; i<G[v].size(); i++)
        {
            edge &e=G[v][i];
            if(e.cap>0 && level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

//通过DFS寻找增广路
int dfs(int v, int t, int f)
{
    if(v==t)
        return f;
    for(int &i=iter[v];  i<G[v].size(); i++)
    {
        edge &e=G[v][i];
        if(e.cap>0 && level[v]<level[e.to])
        {
            int  d=dfs(e.to, t, min(f, e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}

//求解从s到t的最大流
int max_flow(int s, int t)
{
    int flow=0;
    while(true)
    {
        bfs(s);
        if(level[t]<0)
            return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f=dfs(s, t, INF))>0)
            flow+=f;
    }
}

const int MAX_N=107, MAX_F=107, MAX_D=107;

int N, F, D;
bool likeF[MAX_N][MAX_F];
bool likeD[MAX_N][MAX_D];


int main()
{
    scanf("%d%d%d", &N, &F, &D);
    for(int i=0; i<N; i++)
    {
        int Fc, Dc;
        scanf("%d%d", &Fc, &Dc);
        for(int j=0; j<Fc; j++)
        {
            int buf;
            scanf("%d", &buf);
            buf--;
            likeF[i][buf]=true;
        }
        for(int j=0; j<Dc; j++)
        {
            int buf;
            scanf("%d", &buf);
            buf--;
            likeD[i][buf]=true;
        }
    }

    //0~N-1:食物一侧的牛
    //N~2N-1:饮料一侧的牛
    //2N~2N+F-1:食物
    //2N+F~2N+F+D-1:饮料
    int s=N*2+F+D, t=s+1;

    //在s与食物之间连边
    for(int i=0; i<F; i++)
        add_edge(s, N*2+i, 1);

    //在饮料和t之间连边
    for(int i=0; i<D; i++)
        add_edge(N*2+F+i, t, 1);

    //连关于牛的边
    for(int i=0; i<N; i++)
    {
        add_edge(i, N+i, 1);
        for(int j=0; j<F; j++)
            if(likeF[i][j])
                add_edge(N*2+j, i, 1);
        for(int j=0; j<D; j++)
            if(likeD[i][j])
                add_edge(N+i, N*2+F+j, 1);
    }


    printf("%d\n", max_flow(s, t));



    return 0;
}
