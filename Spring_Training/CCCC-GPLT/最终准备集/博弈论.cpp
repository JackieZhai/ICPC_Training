///博弈论相关

/**
非常重要的一种模型：
    Alice先手，Bob后手；
    N堆石子Xi,
    K种取法Ai，
    利用Grundy数转化为Nim问题，异或为零必败。
*/
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_N=1000007, MAX_K=107, MAX_X=10007;

int N, K, X[MAX_N], A[MAX_K];

//利用动态规划求grundy值的数组
int grundy[MAX_X];

int main()
{
    //输入
    scanf("%d%d", &N, &K);
    for(int i=0; i<K; i++)
        scanf("%d", &A[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &X[i]);

    //轮到自己时剩余0必败
    grundy[0]=0;

    //计算grundy值
    int max_x=*max_element(X, X+N);
    for(int j=1; j<=max_x; j++)
    {
        set<int> s;
        for(int i=0; i<K; i++)
            if(A[i]<=j)
                s.insert(grundy[j-A[i]]);
        int g=0;
        while(s.count(g)!=0)
            g++;
        grundy[j]=g;
    }

    //Nim判断胜负
    int x=0;
    for(int i=0; i<N; i++)
        x^=grundy[X[i]];
    if(x!=0)
        puts("Alice");
    else
        puts("Bob");

    return 0;
}
