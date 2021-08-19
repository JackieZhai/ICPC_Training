/**
练习题：World of Darkraft_Codeforces 138D
    由于激光的方向，所以首先将棋盘染成国际象棋棋盘的黑白两色：
    这样将整个游戏一分为二，只有颜色相同的点才属于同一个子游戏。
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N=20;

int H, W;
char board[MAX_N + 1][MAX_N + 1];

int dp[2 * MAX_N + 1][2 * MAX_N + 1][2 * MAX_N + 1][2 * MAX_N + 1][2];

int grundy(int x_min, int x_max, int y_min, int y_max, int odd)
{
    int &ret = dp[x_min][x_max][y_min][y_max][odd];
    if (ret != -1) return ret;

    char vis[MAX_N *2 + 1] = {0};
    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if (((x + y) & 1) == odd)
            {
                const int x_ = y + x, y_ = y - x + W; //做旋转操作使得分割是横竖分割
                if (x_min <= x_ && x_ < x_max && y_min <= y_ && y_ < y_max)
                {
                    const char cell = board[y][x];
                    int g = 0;
                    if (cell == 'L')
                    {// 垂直于X轴一分为二
                        g = grundy(x_min, x_, y_min, y_max, odd) ^ grundy(x_ + 1, x_max, y_min, y_max, odd);
                    }
                    if (cell == 'R')
                    {// 垂直于Y轴一分为二
                        g = grundy(x_min, x_max, y_min, y_, odd) ^ grundy(x_min, x_max, y_ + 1, y_max, odd);
                    }
                    if (cell == 'X')
                    {// 垂直于XY轴分为四部分
                        g = grundy(x_min, x_, y_min, y_, odd) ^
                            grundy(x_min, x_, y_ + 1, y_max, odd) ^
                            grundy(x_ + 1, x_max, y_min, y_, odd) ^
                            grundy(x_ + 1, x_max, y_ + 1, y_max, odd);
                    }
                    vis[g] = 1;
                }
            }
        }
    }

    while (vis[++ret]);
    return ret;
}

int main()
{

    scanf("%d%d", &H, &W);
    for (int i = 0; i < H; ++i)
    {
        scanf(" %s ", board[i]);
    }
    memset(dp, -1, sizeof(dp));

    puts(grundy(0, H + W, 0, H + W, 0) ^ grundy(0, H + W, 0, H + W, 1) ? "WIN" : "LOSE");



    return 0;
}
