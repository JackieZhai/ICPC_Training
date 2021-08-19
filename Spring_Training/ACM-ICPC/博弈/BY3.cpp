/**
��ϰ�⣺Nim_POJ 2068
    �ݹ�����dp
*/
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N = 10;
const int MAX_S = 1 << 13;

int n, S;
int M[2][MAX_N];
bool win[2][MAX_N][MAX_S];             // win[k][j][i]:=��k֧�������ֵ���j����Ա��ʣ��i��ʯͷ��״̬

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
    for (int i = 0; i <= S; ++i)         // ʯͷ����
    {
        for (int k = 0; k < 2; ++k)          // ������
        {
            for (int j = 0; j < n; ++j)       // ��Ա���
            {
                if (i == 0)
                {
                    win[k][j][i] = true;   // û��ʯͷ����ʤ̬
                    continue;
                }
                win[k][j][i] = false;
                const int nxt_k = k ^ 1;                     // ��һ֧����ı��
                const int nxt_j = (k == 1 ? (j + 1) % n : j);     // ��һ����Ա�ı��
                for (int t = 1; t <= M[k][j] && i - t >= 0; ++t)   // ��������1��M[k][j]��ʯͷ
                {
                    win[k][j][i] |= !win[nxt_k][nxt_j][i - t];    // ֻҪ����״̬��һ���ذ�̬����ǰΪ��ʤ̬
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
