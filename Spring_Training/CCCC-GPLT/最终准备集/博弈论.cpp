///���������

/**
�ǳ���Ҫ��һ��ģ�ͣ�
    Alice���֣�Bob���֣�
    N��ʯ��Xi,
    K��ȡ��Ai��
    ����Grundy��ת��ΪNim���⣬���Ϊ��ذܡ�
*/
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_N=1000007, MAX_K=107, MAX_X=10007;

int N, K, X[MAX_N], A[MAX_K];

//���ö�̬�滮��grundyֵ������
int grundy[MAX_X];

int main()
{
    //����
    scanf("%d%d", &N, &K);
    for(int i=0; i<K; i++)
        scanf("%d", &A[i]);
    for(int i=0; i<N; i++)
        scanf("%d", &X[i]);

    //�ֵ��Լ�ʱʣ��0�ذ�
    grundy[0]=0;

    //����grundyֵ
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

    //Nim�ж�ʤ��
    int x=0;
    for(int i=0; i<N; i++)
        x^=grundy[X[i]];
    if(x!=0)
        puts("Alice");
    else
        puts("Bob");

    return 0;
}
