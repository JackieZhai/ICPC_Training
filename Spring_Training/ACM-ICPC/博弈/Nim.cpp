#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=107;

int N, A[MAX_N];


int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i]);

    int x=0;
    for(int i=0; i<N; i++)
        x^=A[i];

    if(x!=0)
        puts("Alice");
    else
        puts("Bob");



    return 0;
}
