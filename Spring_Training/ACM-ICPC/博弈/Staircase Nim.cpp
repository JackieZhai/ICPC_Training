#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=10007;

int N;
int P[MAX_N];


int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", &P[i]);

        if(N%2==1)
            P[N++]=0;
        sort(P, P+N);

        int x=0; //初始化为零
        for(int i=0; i<N-1; i+=2)
            x^=(P[i+1]-P[i]-1);

        if(x==0) //等于零是必败态
            puts("Bob will win");
        else
            puts("Georgia will win");

    }


    return 0;
}
