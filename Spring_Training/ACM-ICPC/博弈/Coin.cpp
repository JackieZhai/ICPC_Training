#include <cstdio>
using namespace std;

const int MAX_K=10, MAX_X=10;


int X, K, A[MAX_K];
bool win[MAX_X+1];


int main()
{
    scanf("%d", &X);
    scanf("%d", &K);
    for(int i=0; i<K; i++)
        scanf("%d", &A[i]);


    win[0]=false;
    for(int j=1; j<=X; j++)
    {
        win[j]=false;
        for(int i=0; i<K; i++)
            win[j] |= A[i]<=j && !win[j-A[i]];
    }

    if(win[X])
        puts("Alice");
    else
        puts("Bob");

    return 0;
}
