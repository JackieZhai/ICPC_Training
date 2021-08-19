/**
例题：Physics Experiment_POJ 3684

*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double g=10.0; //重力加速度
const int MAX_N=107;

int N, H, R, T;
double y[MAX_N];

//求T时刻球的位置
double calc(int T)
{
    if(T<0)
        return H;
    double t=sqrt(2*H/g);
    int k=(int)(T/t);
    if(k%2==0)
    {
        double d=T-k*t;
        return H-g*d*d/2;
    }
    else
    {
        double d=k*t+t-T;
        return H-g*d*d/2;
    }
}

int main()
{
    int C;
    scanf("%d", &C);

    while(C--)
    {
        scanf("%d%d%d%d", &N, &H, &R, &T);


        for(int i=0; i<N; i++)
        {
            y[i]=calc(T-i);
        }
        sort(y, y+N);
        for(int i=0; i<N; i++)
        {
            printf("%.2f%c", y[i]+2*R*i/100.0, i+1==N? '\n':' ');
        }
    }




    return 0;
}
