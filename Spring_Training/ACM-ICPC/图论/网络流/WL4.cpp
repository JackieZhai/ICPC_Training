/**
���⣺Dining_POJ 3281
    ��ע��Ŀ��滮�Ľ�ͼ����
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


const int INF=0x3f3f3f3f;
const int MAX_V=1007;

//���ڱ�ʾ�ߵĽṹ��(�յ㡢�����������)
struct edge{
    int to, cap, rev;
};

vector<edge> G[MAX_V]; //ͼ���ڽӱ��ʾ
int level[MAX_V]; //���㵽Դ��ľ�����
int iter[MAX_V]; //��ǰ��������֮ǰ�ı��Ѿ�û������

//��ͼ������һ����s��t������Ϊcap�ı�
void add_edge(int from, int to, int cap)
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size()-1});
}

//ͨ��BFS�����Դ������ľ�����
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

//ͨ��DFSѰ������·
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

//����s��t�������
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

    //0~N-1:ʳ��һ���ţ
    //N~2N-1:����һ���ţ
    //2N~2N+F-1:ʳ��
    //2N+F~2N+F+D-1:����
    int s=N*2+F+D, t=s+1;

    //��s��ʳ��֮������
    for(int i=0; i<F; i++)
        add_edge(s, N*2+i, 1);

    //�����Ϻ�t֮������
    for(int i=0; i<D; i++)
        add_edge(N*2+F+i, t, 1);

    //������ţ�ı�
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
