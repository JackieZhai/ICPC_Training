/**
练习题：Nim_POJ 2068
    递归搜索dp
*/
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N = 10;
const int MAX_S = 1 << 13;

int n, S;
int M[2][MAX_N];
bool win[2][MAX_N][MAX_S];             // win[k][j][i]:=第k支队伍在轮到第j名队员且剩余i块石头的状态

bool input()
{
    scanf("%d%d", &n, &S);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", M[0] + i, M[1] + i);
    }

    return n > 0;
}

bool solve()
{
    for (int i = 0; i <= S; ++i)         // 石头数量
    {
        for (int k = 0; k < 2; ++k)          // 队伍编号
        {
            for (int j = 0; j < n; ++j)       // 队员编号
            {
                if (i == 0)
                {
                    win[k][j][i] = true;   // 没有石头，必胜态
                    continue;
                }
                win[k][j][i] = false;
                const int nxt_k = k ^ 1;                     // 下一支队伍的编号
                const int nxt_j = (k == 1 ? (j + 1) % n : j);     // 下一个队员的编号
                for (int t = 1; t <= M[k][j] && i - t >= 0; ++t)   // 尝试拿走1到M[k][j]个石头
                {
                    win[k][j][i] |= !win[nxt_k][nxt_j][i - t];    // 只要后续状态有一个必败态，则当前为必胜态
                }
            }
        }
    }

    return win[0][0][S];
}


int main()
{
    while (input())
        puts(solve() ? "1" : "0");

    return 0;
}
