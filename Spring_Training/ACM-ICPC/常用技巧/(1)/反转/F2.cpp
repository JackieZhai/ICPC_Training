/**
例题：Fliptile_POJ 3279
    先确定第一行，则所有确定；
    判断最后一行就可以知道是否可行
*/
#include <cstdio>
#include <cstring>
using namespace std;

//邻接的格子的坐标
const int dx[]={-1, 0, 0, 0, 1};
const int dy[]={0, -1, 0, 1, 0};
const int MAX_M=17, MAX_N=17;

int M, N;
int tile[MAX_M][MAX_N];

int opt[MAX_M][MAX_N]; //保存最优解
int flip[MAX_M][MAX_N]; //保存中间结果

//查询(x, y)的颜色
int get(int x, int y)
{
    int c=tile[x][y];
    for(int d=0;  d<5; d++)
    {
        int x2=x+dx[d], y2=y+dy[d];
        if(0<=x2 && x2<M && 0<=y2 && y2<N)
        {
            c+=flip[x2][y2];
        }
    }
    return c%2;
}

//求出第1行确定情况下的最小操作数
//不存在解的情况返回-1
int calc()
{
    //求出从第2行开始的反转方法
    for(int i=1; i<M; i++)
        for(int j=0; j<N; j++)
            if(get(i-1, j)!=0)
            {
                //(i-1, j)是黑色的话，则必须反转这个格子
                flip[i][j]=1;
            }

    //判断最后一行时候全白
    for(int j=0; j<N; j++)
        if(get(M-1, j)!=0)
        {
            //无解
            return -1;
        }

    //统计反转的次数
    int res=0;
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
        {
            res+=flip[i][j];
        }

    return res;
}

int main()
{
    scanf("%d%d", &M, &N);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &tile[i][j]);


    int res=-1;

    //按照字典序尝试第一行的所有可能性
    for(int i=0; i<1<<N; i++)
    {
        memset(flip, 0, sizeof(flip));
        for(int j=0; j<N; j++)
            flip[0][N-j-1]=i>>j&1;
        int num=calc();
        if(num>=0 && (res<0 || res>num))
        {
            res=num;
            memcpy(opt, flip, sizeof(flip));
        }
    }

    if(res<0)
    {
        //无解
        printf("IMPOSSIBLE\n");
    }
    else
    {
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                printf("%d%c", opt[i][j], j+1==N?'\n':' ');
            }
        }
    }



    return 0;
}
