/**
例题：Evacuation_POJ 3057
     注意图的大小不能太小，否则RE
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_X=27, MAX_Y=27;
const int dx[4]={-1, 0, 0, 1};
const int dy[4]={0, -1, 1, 0};

const int MAX_V=10007;

int V;
vector<int> G[MAX_V];
int match[MAX_V]; //所匹配的顶点
int used[MAX_V];

void add_edge(int u, int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v)
{
    used[v]=true;
    for(int i=0; i<G[v].size(); i++)
    {
        int u=G[v][i], w=match[u];
        if(w<0 || !used[w] && dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}



int X, Y;
char field[MAX_X][MAX_Y];

vector<int> dX, dY; //门的坐标
vector<int> pX, pY; //人的坐标
int dist[MAX_X][MAX_Y][MAX_X][MAX_Y]; //最近距离

//通过BFS计算最近距离
void bfs(int x, int y, int d[MAX_X][MAX_Y])
{
    queue<int> qx, qy;
    d[x][y]=0;
    qx.push(x);
    qy.push(y);
    while(!qx.empty())
    {
        x=qx.front(); qx.pop();
        y=qy.front(); qy.pop();
        for(int k=0; k<4; k++)
        {
            int x2=x+dx[k], y2=y+dy[k];
            if(0<=x2 && x2<X && 0<=y2 && y2<Y && field[x2][y2]=='.' && d[x2][y2]<0)
            {
                d[x2][y2]=d[x][y]+1;
                qx.push(x2);
                qy.push(y2);
            }
        }

    }
}



int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &X, &Y);
        for(int i=0; i<X; i++)
            scanf("%s", &field[i]);

        int n=X*Y;
        dX.clear(); dY.clear();
        pX.clear(); pY.clear();
        memset(dist, -1, sizeof(dist));

        //计算到各个门的最近距离
        for(int x=0; x<X; x++)
            for(int y=0; y<Y; y++)
            {
                if(field[x][y]=='D')
                {
                    dX.push_back(x);
                    dY.push_back(y);
                    bfs(x, y, dist[x][y]);
                }
                else if(field[x][y]=='.')
                {
                    pX.push_back(x);
                    pY.push_back(y);
                }
            }

        //建图
        int d=dX.size(), p=pX.size();
        V=n*d;
        for(int i=0; i<V; i++) //清空图
            G[i].clear();
        for(int i=0; i<d; i++)
            for(int j=0; j<p; j++)
                if(dist[dX[i]][dY[i]][pX[j]][pY[j]]>=0)
                    for(int k=dist[dX[i]][dY[i]][pX[j]][pY[j]]; k<=n; k++)
                        add_edge((k-1)*d+i, n*d+j);


        //求解所有人安全逃脱所用的时间
        if(p==0)
        {
            printf("0\n");
            continue;
        }
        int num=0;
        memset(match, -1, sizeof(match));
        bool flag=false;
        for(int v=0; v<V; v++)
        {
            memset(used, 0, sizeof(used));
            if(dfs(v))
            {
                if(++num==p)
                {
                    printf("%d\n", v/d+1);
                    flag=true;
                    break;
                }
            }
        }
        if(flag)
            continue;
        printf("impossible\n");


    }



    return 0;
}
